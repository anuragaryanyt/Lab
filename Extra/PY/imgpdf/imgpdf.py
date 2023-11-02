from flask import Flask, render_template, request, send_file, redirect, url_for
from fpdf import FPDF
from PIL import Image

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
        pdf.add_page()

        # Get image dimensions using Pillow
        img = Image.open(image)
        img_width, img_height = img.size

        # Set width and height in PDF
        pdf.image(image, x=10, y=10, w=190, h=190 * img_height / img_width)

    pdf_output_path = "yourfile.pdf"
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
