import qrcode

statuses = ["shipped", "in transit", "out for delivery", "delivered"]

for status in statuses:
    img = qrcode.make(status)
    img.save(f"{status}.png")
