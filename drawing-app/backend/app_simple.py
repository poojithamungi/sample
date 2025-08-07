from flask import Flask, render_template, request, jsonify, redirect, url_for, flash
from flask_socketio import SocketIO, emit, join_room, leave_room
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, logout_user, login_required, current_user
from flask_cors import CORS
import bcrypt
import os
from datetime import datetime
import json

# Initialize Flask app
app = Flask(__name__)
app.config['SECRET_KEY'] = 'your-secret-key-change-this-in-production'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///drawing_app.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# Initialize extensions
db = SQLAlchemy(app)
socketio = SocketIO(app, cors_allowed_origins="*", async_mode='threading')
login_manager = LoginManager()
login_manager.init_app(app)
login_manager.login_view = 'login'
CORS(app)

# Define models here to avoid circular imports
class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    email = db.Column(db.String(120), unique=True, nullable=False)
    password_hash = db.Column(db.String(128), nullable=False)
    created_at = db.Column(db.DateTime, default=datetime.utcnow)
    
    # Relationship with drawings
    drawings = db.relationship('Drawing', backref='user', lazy=True)
    
    def __repr__(self):
        return f'<User {self.username}>'

class Drawing(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    room_id = db.Column(db.String(50), nullable=False, default='default')
    canvas_data = db.Column(db.Text, nullable=False)  # JSON string of canvas data
    created_at = db.Column(db.DateTime, default=datetime.utcnow)
    
    def __repr__(self):
        return f'<Drawing {self.id} by User {self.user_id}>'

class DrawingSession(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    room_id = db.Column(db.String(50), unique=True, nullable=False)
    name = db.Column(db.String(100), nullable=False)
    created_by = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    created_at = db.Column(db.DateTime, default=datetime.utcnow)
    is_active = db.Column(db.Boolean, default=True)
    
    def __repr__(self):
        return f'<DrawingSession {self.room_id}>'

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

# Routes
@app.route('/')
def index():
    if current_user.is_authenticated:
        return render_template('drawing.html')
    return render_template('login.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        data = request.get_json()
        username = data.get('username')
        password = data.get('password')
        
        user = User.query.filter_by(username=username).first()
        if user and bcrypt.checkpw(password.encode('utf-8'), user.password_hash):
            login_user(user)
            return jsonify({'success': True, 'redirect': url_for('index')})
        else:
            return jsonify({'success': False, 'message': 'Invalid credentials'})
    
    return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        data = request.get_json()
        username = data.get('username')
        email = data.get('email')
        password = data.get('password')
        
        if User.query.filter_by(username=username).first():
            return jsonify({'success': False, 'message': 'Username already exists'})
        
        if User.query.filter_by(email=email).first():
            return jsonify({'success': False, 'message': 'Email already exists'})
        
        password_hash = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
        user = User(username=username, email=email, password_hash=password_hash)
        db.session.add(user)
        db.session.commit()
        
        login_user(user)
        return jsonify({'success': True, 'redirect': url_for('index')})
    
    return render_template('register.html')

@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('login'))

@app.route('/save-drawing', methods=['POST'])
@login_required
def save_drawing():
    data = request.get_json()
    canvas_data = data.get('canvas_data')
    room_id = data.get('room_id', 'default')
    
    drawing = Drawing(
        user_id=current_user.id,
        room_id=room_id,
        canvas_data=canvas_data,
        created_at=datetime.utcnow()
    )
    db.session.add(drawing)
    db.session.commit()
    
    return jsonify({'success': True, 'message': 'Drawing saved successfully'})

@app.route('/load-drawing/<int:drawing_id>')
@login_required
def load_drawing(drawing_id):
    drawing = Drawing.query.get_or_404(drawing_id)
    return jsonify({
        'success': True,
        'canvas_data': drawing.canvas_data,
        'created_at': drawing.created_at.isoformat()
    })

@app.route('/get-drawings')
@login_required
def get_drawings():
    drawings = Drawing.query.filter_by(user_id=current_user.id).order_by(Drawing.created_at.desc()).limit(10).all()
    return jsonify({
        'success': True,
        'drawings': [{
            'id': d.id,
            'room_id': d.room_id,
            'created_at': d.created_at.isoformat()
        } for d in drawings]
    })

# Socket.IO events
@socketio.on('connect')
def handle_connect():
    print(f'Client connected: {request.sid}')

@socketio.on('disconnect')
def handle_disconnect():
    print(f'Client disconnected: {request.sid}')

@socketio.on('join_room')
def handle_join_room(data):
    room = data.get('room', 'default')
    join_room(room)
    emit('user_joined', {'user': current_user.username if current_user.is_authenticated else 'Anonymous'}, room=room)

@socketio.on('leave_room')
def handle_leave_room(data):
    room = data.get('room', 'default')
    leave_room(room)
    emit('user_left', {'user': current_user.username if current_user.is_authenticated else 'Anonymous'}, room=room)

@socketio.on('draw')
def handle_draw(data):
    room = data.get('room', 'default')
    emit('draw', data, room=room, include_self=False)

@socketio.on('clear_canvas')
def handle_clear_canvas(data):
    room = data.get('room', 'default')
    emit('clear_canvas', data, room=room)

@socketio.on('change_color')
def handle_change_color(data):
    room = data.get('room', 'default')
    emit('change_color', data, room=room)

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    socketio.run(app, debug=True, host='0.0.0.0', port=5000) 