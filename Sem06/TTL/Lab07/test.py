# !pip install opencv-python
# from google.colab.patches import cv2_imshow
import cv2

color_image = cv2.imread('color_image.jpg')
cv2.imshow(color_image)

if color_image is None:
    print("Error: Could not read the image.")
    exit()

# to grayscale
gray_image = cv2.cvtColor(color_image, cv2.COLOR_BGR2GRAY)
rgb_image = cv2.cvtColor(gray_image, cv2.COLOR_GRAY2BGR)
hsv_image = cv2.cvtcolor(color_image, cv2.COLOR_HSV)

cv2.imshow ('Grayscale image', gray_image)
cv2.imshow ('RGB image',rgb_image)
cv2.imshow('HSV image', hsv_image)

cv2.waitKey(0)
cv2.destroyAllWindows()

cv2.imwrite('gray_image.jpg', gray_image)
print("Grayscale image saved.")

cv2.imwrite('rgb_image.jpg', rgb_image)
print("RGB image saved.")
