from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

# Global variable to store tracking status
tracking_status = 'shipped'

# Endpoint to get the current tracking status
@app.route('/api/get_status', methods=['GET'])
def get_status():
    global tracking_status
    return jsonify({'status': tracking_status})

# Endpoint to update the tracking progress
@app.route('/api/update_progress', methods=['POST'])
def update_progress():
    global tracking_status
    data = request.json
    status = data.get('status')
    if status:
        # Update tracking progress based on received status
        tracking_status = status
        return jsonify({'message': 'Progress updated successfully'}), 200
    else:
        return jsonify({'error': 'Invalid request'}), 400

# Route to serve the HTML file
@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True)

    