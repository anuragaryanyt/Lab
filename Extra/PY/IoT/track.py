
import cv2
import requests
import time

# URL of the web server's API endpoint
API_ENDPOINT = 'http://localhost:5000/api/update_progress'

def scan_qr_code():
    qr_code_detector = cv2.QRCodeDetector()
    cap = cv2.VideoCapture(0)

    while True:
        _, frame = cap.read()
        data, _, _ = qr_code_detector.detectAndDecode(frame)
        
        if data:
            # Send scanned data to web server
            payload = {'status': data}
            response = requests.post(API_ENDPOINT, json=payload)
            if response.status_code == 200:
                print("Progress updated successfully:", data)
            else:
                print("Failed to update progress")
                print("Response content:", response.content)  # Log response content

        cv2.imshow("QR Code Scanner", frame)
        if cv2.waitKey(1) == ord("q"):
            break

    cap.release()
    cv2.destroyAllWindows()

# Continuously scan for QR codes
while True:
    scan_qr_code()
    time.sleep(2)  # Add a delay to control scanning frequency
