import fpdf
from fpdf import FPDF
ImageList = ['K:\Lab\Extra\PY\image1.png','K:\Lab\Extra\PY\image2.png']
pdf=FPDF()
for image in ImageList:
    pdf.add_page()
    pdf.image(image,x=10,y=10,w=190,h=250)
pdf.output("yourfile.pdf","F")


