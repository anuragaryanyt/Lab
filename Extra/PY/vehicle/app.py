from flask import Flask, render_template, request, jsonify
import cv2
import pytesseract
import csv

app = Flask(__name__)

# Load the dataset into memory
dataset = {}
with open('number.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        dataset[row['Number']] = row

def detect_number_plate(image_path):
    # Load the image
    image = cv2.imread(image_path)

    # Convert the image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Perform edge detection
    edges = cv2.Canny(gray, 150, 200)

    # Find contours in the edge-detected image
    contours, _ = cv2.findContours(edges.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Get the largest contour (presumably the number plate)
    largest_contour = max(contours, key=cv2.contourArea)

    # Get the bounding box of the contour
    x, y, w, h = cv2.boundingRect(largest_contour)

    # Crop the number plate region
    number_plate = gray[y:y+h, x:x+w]

    # Use pytesseract to perform OCR on the number plate
    plate_number = pytesseract.image_to_string(number_plate, config='--psm 6')

    return plate_number.strip()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/detect', methods=['POST'])
def detect_plate():
    # Get the image file from the POST request
    image_file = request.files['image']

    # Save the image temporarily
    temp_image_path = 'temp_image.jpg'
    image_file.save(temp_image_path)

    # Detect the number plate
    plate_number = detect_number_plate(temp_image_path)

    # Delete the temporary image
    import os
    os.remove(temp_image_path)

    # Lookup the plate number in the dataset
    if plate_number in dataset:
        return jsonify(dataset[plate_number])
    else:
        return jsonify({'error': 'Vehicle not found'})

if __name__ == '__main__':
    app.run(debug=True)
