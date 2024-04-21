import tempfile
from flask import Flask, render_template, request, send_file, redirect, url_for
from fpdf import FPDF
from PIL import Image
import os

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/generate_pdf', methods=['POST'])
def generate_pdf():
    if 'images[]' not in request.files:
        return "No file part"

    pdf = FPDF()
    images = request.files.getlist('images[]')

    for image in images:
        # Create a temporary directory if it doesn't exist
        temp_dir = tempfile.mkdtemp()

        # Save the image to a temporary file
        temp_file_path = os.path.join(temp_dir, image.filename)
        with open(temp_file_path, 'wb') as temp_file:
            temp_file.write(image.read())

        # Open the image with Pillow to get dimensions
        img = Image.open(temp_file_path)
        img_width, img_height = img.size

        pdf.add_page()

        # Set width and height in PDF
        pdf.image(temp_file_path, x=10, y=10, w=190, h=190 * img_height / img_width)

        # Close the image
        img.close()

        # Clean up temporary file and directory
        os.remove(temp_file_path)
        os.rmdir(temp_dir)

    # pdf_output_path = "yourfile.pdf"
    pdf_output_path = os.path.join(app.root_path, 'yourfile.pdf')
    pdf.output(pdf_output_path, "F")

    # Redirect to a success page with the option to download
    return redirect(url_for('success', filename='yourfile.pdf'))


@app.route('/success/<filename>')
def success(filename):
    return render_template('success.html', filename=filename)

@app.route('/download/<filename>')
def download(filename):
    return send_file(filename, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
