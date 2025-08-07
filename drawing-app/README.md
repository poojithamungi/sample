# 🎨 Collaborative Drawing Board

A real-time collaborative drawing web application built with Python Flask, Socket.IO, and modern web technologies. Multiple users can draw together in real-time, with features like user authentication, room-based collaboration, and drawing persistence.

## ✨ Features

### 🎯 Core Features
- **Real-time Collaboration**: Multiple users can draw simultaneously
- **User Authentication**: Secure login/registration system with bcrypt hashing
- **Room-based Sessions**: Join different drawing rooms
- **Drawing Tools**: Pen, brush, eraser with customizable colors and sizes
- **Live User Tracking**: See who's currently in the room
- **Drawing Persistence**: Save and load drawings from database
- **Export Functionality**: Export drawings as PNG files

### 🛠️ Technical Features
- **WebSocket Communication**: Real-time bidirectional communication
- **Responsive Design**: Works on desktop and mobile devices
- **SQLite Database**: Store user data and drawing sessions
- **Session Management**: Secure user sessions with Flask-Login
- **CORS Support**: Cross-origin resource sharing enabled

## 🏗️ Architecture

```
drawing-app/
├── backend/
│   ├── app.py                 # Main Flask application
│   ├── models/
│   │   ├── user.py           # User authentication model
│   │   └── drawing.py        # Drawing and session models
│   └── templates/
│       ├── login.html         # Login page
│       ├── register.html      # Registration page
│       └── drawing.html       # Main drawing interface
├── requirements.txt           # Python dependencies
└── README.md                 # This file
```

## 🚀 Quick Start

### Prerequisites
- Python 3.7 or higher
- pip (Python package installer)

### Installation

1. **Clone or download the project**
   ```bash
   cd drawing-app
   ```

2. **Install Python dependencies**
   ```bash
   pip install -r requirements.txt
   ```

3. **Run the application**
   ```bash
   cd backend
   python app.py
   ```

4. **Open your browser**
   - Go to: `http://localhost:5000`
   - Register a new account or login
   - Start drawing collaboratively!

## 📖 Usage Guide

### 🔐 Authentication
1. **Register**: Create a new account with username, email, and password
2. **Login**: Use your credentials to access the drawing board
3. **Logout**: Click the logout button to end your session

### 🎨 Drawing Interface
1. **Tools**: Choose between Pen, Brush, or Eraser
2. **Color**: Use the color picker to select drawing colors
3. **Size**: Adjust brush size with the slider (1-50px)
4. **Canvas**: Click and drag to draw on the white canvas

### 👥 Collaboration
1. **Join Room**: Enter a room name and click "Join Room"
2. **Real-time Drawing**: See other users' drawings in real-time
3. **Active Users**: View who's currently in the room
4. **Multiple Rooms**: Create different rooms for different projects

### 💾 Save & Export
1. **Save Drawing**: Click "Save" to store the current canvas
2. **Export PNG**: Click "Export PNG" to download as image
3. **Clear Canvas**: Click "Clear" to start fresh

## 🔧 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | `/` | Main drawing interface (requires login) |
| GET | `/login` | Login page |
| POST | `/login` | Authenticate user |
| GET | `/register` | Registration page |
| POST | `/register` | Create new user account |
| GET | `/logout` | Logout user |
| POST | `/save-drawing` | Save current canvas |
| GET | `/load-drawing/<id>` | Load specific drawing |
| GET | `/get-drawings` | Get user's saved drawings |

## 🔌 WebSocket Events

| Event | Direction | Description |
|-------|-----------|-------------|
| `connect` | Client → Server | Client connects |
| `disconnect` | Client → Server | Client disconnects |
| `join_room` | Client → Server | Join drawing room |
| `leave_room` | Client → Server | Leave drawing room |
| `draw` | Bidirectional | Drawing coordinates and data |
| `clear_canvas` | Bidirectional | Clear the canvas |
| `change_color` | Bidirectional | Change drawing color |
| `user_joined` | Server → Client | User joined room |
| `user_left` | Server → Client | User left room |

## 🗄️ Database Schema

### Users Table
```sql
CREATE TABLE user (
    id INTEGER PRIMARY KEY,
    username VARCHAR(80) UNIQUE NOT NULL,
    email VARCHAR(120) UNIQUE NOT NULL,
    password_hash VARCHAR(128) NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);
```

### Drawings Table
```sql
CREATE TABLE drawing (
    id INTEGER PRIMARY KEY,
    user_id INTEGER NOT NULL,
    room_id VARCHAR(50) NOT NULL,
    canvas_data TEXT NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES user (id)
);
```

### Drawing Sessions Table
```sql
CREATE TABLE drawing_session (
    id INTEGER PRIMARY KEY,
    room_id VARCHAR(50) UNIQUE NOT NULL,
    name VARCHAR(100) NOT NULL,
    created_by INTEGER NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    is_active BOOLEAN DEFAULT TRUE,
    FOREIGN KEY (created_by) REFERENCES user (id)
);
```

## 🛠️ Development

### Project Structure
```
drawing-app/
├── backend/
│   ├── app.py                 # Flask app with SocketIO
│   ├── models/                # Database models
│   │   ├── user.py           # User model
│   │   └── drawing.py        # Drawing models
│   └── templates/             # HTML templates
│       ├── login.html         # Login page
│       ├── register.html      # Registration page
│       └── drawing.html       # Drawing interface
├── requirements.txt           # Python dependencies
└── README.md                 # Documentation
```

### Key Technologies
- **Backend**: Flask, Flask-SocketIO, Flask-SQLAlchemy, Flask-Login
- **Database**: SQLite (can be easily changed to PostgreSQL/MySQL)
- **Authentication**: bcrypt for password hashing
- **Real-time**: Socket.IO for WebSocket communication
- **Frontend**: HTML5 Canvas, JavaScript, CSS3
- **Styling**: Modern CSS with gradients and responsive design

## 🔒 Security Features

- **Password Hashing**: bcrypt for secure password storage
- **Session Management**: Flask-Login for secure sessions
- **Input Validation**: Server-side validation for all inputs
- **CORS Protection**: Configured for secure cross-origin requests
- **SQL Injection Protection**: SQLAlchemy ORM prevents SQL injection

## 🚀 Deployment

### Local Development
```bash
cd drawing-app/backend
python app.py
```

### Production Deployment
1. **Install dependencies**: `pip install -r requirements.txt`
2. **Set environment variables**:
   ```bash
   export FLASK_ENV=production
   export SECRET_KEY=your-secure-secret-key
   ```
3. **Use a production WSGI server**:
   ```bash
   gunicorn -w 4 -k gevent -b 0.0.0.0:5000 app:app
   ```

### Docker Deployment
```dockerfile
FROM python:3.9-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt
COPY . .
EXPOSE 5000
CMD ["python", "app.py"]
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📝 License

This project is licensed under the MIT License.

## 🆘 Troubleshooting

### Common Issues

1. **Port already in use**
   ```bash
   # Change port in app.py
   socketio.run(app, debug=True, host='0.0.0.0', port=5001)
   ```

2. **Database errors**
   ```bash
   # Delete the database file and restart
   rm backend/drawing_app.db
   python app.py
   ```

3. **Socket.IO connection issues**
   - Check if the server is running
   - Ensure no firewall blocking port 5000
   - Check browser console for errors

4. **Drawing not syncing**
   - Verify WebSocket connection in browser console
   - Check if users are in the same room
   - Ensure server is receiving drawing events

## 🎯 Future Enhancements

- [ ] **Multiple brush types** (spray, calligraphy, etc.)
- [ ] **Layer system** for complex drawings
- [ ] **Undo/Redo functionality**
- [ ] **Drawing templates and shapes**
- [ ] **Video recording of drawing sessions**
- [ ] **Mobile touch support optimization**
- [ ] **Real-time chat in rooms**
- [ ] **Drawing history and playback**

---

**Happy Drawing! 🎨✨** 