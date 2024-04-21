from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    # Get user inputs from the form
    a = int(request.form['no1'])
    b = int(request.form['no2'])

    # Perform the calculation
    result = a + b

    # Pass the result back to the HTML page
    return render_template('result.html', result=result)

if __name__ == '__main__':
    app.run(debug=True)
