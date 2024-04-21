# app.py
from flask import Flask, render_template, Response, jsonify
from pyzbar.pyzbar import decode
import cv2

app = Flask(__name__)
camera = cv2.VideoCapture(0)

tracking_status = "Unknown"  # Initialize tracking status

def generate_frames():
    while True:
        success, frame = camera.read()
        if not success:
            break
        else:
            decoded_objects = decode(frame)
            if decoded_objects:
                decoded_data = decoded_objects[0].data.decode('utf-8')
                cv2.putText(frame, f"QR Code Detected: {decoded_data}", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                # Update tracking status when QR code is detected
                global tracking_status
                tracking_status = decoded_data
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()
            yield (b'--frame\r\n'
                    b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/api/get_status')
def get_status():
    global tracking_status
    return jsonify({'status': tracking_status})

if __name__ == '__main__':
    app.run(debug=True)
