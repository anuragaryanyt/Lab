# from flask import Flask, render_template, request, send_file
# from fpdf import FPDF
# from PIL import Image

# app = Flask(__name__)

# @app.route('/')
# def index():
#     return render_template('index.html')

# @app.route('/generate_pdf', methods=['POST'])
# def generate_pdf():
#     if 'images[]' not in request.files:
#         return "No file part"

#     pdf = FPDF()
#     images = request.files.getlist('images[]')

#     for image in images:
#         pdf.add_page()

#         # Get image dimensions using Pillow
#         img = Image.open(image)
#         img_width, img_height = img.size

#         # Set desired width in PDF
#         desired_width = 190

#         # Calculate the height to maintain the aspect ratio
#         desired_height = desired_width * img_height / img_width

#         # If the image is in portrait orientation, adjust the height
#         if img_width < img_height:
#             pdf.image(image, x=10, y=10, w=desired_width, h=desired_height)
#         else:
#             # If the image is in landscape orientation, center it within the PDF
#             y_offset = (297 - desired_height) / 2  # assuming A4 page size
#             pdf.image(image, x=10, y=y_offset, w=desired_width, h=desired_height)

#     pdf_output_path = "yourfile.pdf"
#     pdf.output(pdf_output_path, "F")

#     return send_file(pdf_output_path, as_attachment=True)

# if __name__ == '__main__':
#     app.run(debug=True)


from flask import Flask, render_template, request, send_file
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

    return send_file(pdf_output_path, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
