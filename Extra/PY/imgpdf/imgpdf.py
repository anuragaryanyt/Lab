from flask import Flask, render_template, request, send_file
from fpdf import FPDF
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
        pdf.add_page()
        pdf.image(image, x=10, y=10, w=190, h=275)

    # pdf.output("yourfile.pdf", "F")

    pdf_output_path = "yourfile.pdf"
    pdf.output(pdf_output_path, "F")

    return send_file(pdf_output_path, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)

