@echo off
echo.
echo ========================================
echo    Collaborative Drawing App
echo ========================================
echo.

echo Checking if Python is installed...
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ❌ Python is not installed!
    echo Please install Python from: https://python.org/
    echo.
    pause
    exit /b 1
)

echo ✅ Python is installed
echo.

echo Installing dependencies...
pip install -r requirements_minimal.txt
if %errorlevel% neq 0 (
    echo ❌ Failed to install dependencies!
    echo Trying alternative installation...
    pip install Flask Flask-SQLAlchemy Flask-Login Flask-CORS bcrypt
    if %errorlevel% neq 0 (
        echo ❌ Failed to install dependencies!
        pause
        exit /b 1
    )
)

echo ✅ Dependencies installed
echo.

echo Starting Collaborative Drawing App...
echo.
echo 🌐 Server will be available at: http://localhost:5000
echo 📝 Open your browser and go to: http://localhost:5000
echo.
echo Press Ctrl+C to stop the server
echo.

cd backend

echo Trying minimal version first (basic functionality)...
python app_minimal.py
if %errorlevel% neq 0 (
    echo.
    echo Minimal version failed, trying simple version...
    python app_simple.py
    if %errorlevel% neq 0 (
        echo.
        echo Both versions failed. Please check the error messages above.
        pause
    )
) 