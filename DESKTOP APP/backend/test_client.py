import socketio
import time

# Initialize a Socket.IO client
sio = socketio.Client()

# Define event handlers for messages from the backend
@sio.event
def connect():
    print('Client: Connection established with backend!')

@sio.event
def disconnect():
    print('Client: Disconnected from backend.')

@sio.event
def test_started_ack(data):
    print(f"Client: Backend acknowledged test start: {data}")

@sio.event
def test_stopped_ack(data):
    print(f"Client: Backend acknowledged test stop: {data}")

@sio.event
def sensor_data(data):
    # This event will receive the live sensor data from the backend
    # We're just printing it here, but a real frontend would display it.
    print(f"Client: Received live sensor data: {data}")


# --- Main execution ---
try:
    # Connect to your Flask-SocketIO server (running on localhost:5000)
    sio.connect('http://localhost:5000')
    print("Client: Attempting to connect to backend...")

    # Give it a moment to establish connection
    time.sleep(1)

    # Simulate starting a test for a patient_id (replace 1 with a valid patient ID from your DB)
    # This will trigger the @socketio.on('start_test_command') in your app.py
    print("\nClient: Sending 'start_test_command'...")
    sio.emit('start_test_command', {'patientId': 1}) # IMPORTANT: Ensure patientId=1 exists or use a valid one

    # Give time for the backend to process and potentially start streaming data
    print("Client: Waiting for 10 seconds to receive sensor data...")
    time.sleep(10)

    # Simulate stopping the test
    # This will trigger the @socketio.on('stop_test_command') in your app.py
    # Use the test_id you saw in the 'test_started_ack' message from the backend,
    # or if you used patientId=1 and it was the first test, testId=1 is likely correct.
    print("\nClient: Sending 'stop_test_command'...")
    sio.emit('stop_test_command', {'testId': 1}) # IMPORTANT: Use the actual test_id that was started

    time.sleep(2) # Give time for stop command to process

except Exception as e:
    print(f"Client: An error occurred: {e}")
finally:
    if sio.connected:
        sio.disconnect()
        print("Client: Disconnected.")