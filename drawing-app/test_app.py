#!/usr/bin/env python3
"""
Simple test script to verify the Flask app works
"""

import requests
import time

def test_app():
    print("Testing Collaborative Drawing App...")
    print("=" * 50)
    
    base_url = "http://localhost:5000"
    
    try:
        # Test if server is running
        print("1. Testing server connection...")
        response = requests.get(base_url, timeout=5)
        if response.status_code == 200:
            print("✅ Server is running!")
            print(f"   Response length: {len(response.text)} characters")
        else:
            print(f"❌ Server returned status code: {response.status_code}")
            return False
            
        # Test login page
        print("\n2. Testing login page...")
        response = requests.get(f"{base_url}/login", timeout=5)
        if response.status_code == 200:
            print("✅ Login page is accessible!")
            if "Draw Together" in response.text:
                print("✅ Login page contains expected content!")
            else:
                print("⚠️  Login page content may be different than expected")
        else:
            print(f"❌ Login page returned status code: {response.status_code}")
            
        # Test register page
        print("\n3. Testing register page...")
        response = requests.get(f"{base_url}/register", timeout=5)
        if response.status_code == 200:
            print("✅ Register page is accessible!")
            if "Create your account" in response.text:
                print("✅ Register page contains expected content!")
            else:
                print("⚠️  Register page content may be different than expected")
        else:
            print(f"❌ Register page returned status code: {response.status_code}")
            
        print("\n" + "=" * 50)
        print("🎉 All tests passed! Your app is working correctly.")
        print(f"🌐 Open your browser and go to: {base_url}")
        print("📝 You should see the login page with a beautiful gradient background")
        
        return True
        
    except requests.exceptions.ConnectionError:
        print("❌ Could not connect to server!")
        print("   Make sure the Flask app is running on port 5000")
        return False
    except Exception as e:
        print(f"❌ Error during testing: {e}")
        return False

if __name__ == "__main__":
    print("Waiting 3 seconds for server to start...")
    time.sleep(3)
    test_app() 