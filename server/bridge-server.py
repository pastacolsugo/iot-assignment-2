from flask import *
from datetime import datetime
import random
import serial
from queue import Queue
from threading import Thread

app = Flask(__name__)

water_level_data = [('00:00', 100), ('00:01', 102), ('00:02', 108), ('00:03', 100)]

manual_controls_enabled = False
bridge_state = 'normal'
lights_state = 'off'

def serial_task(receive_queue, send_queue):
    arduino_serial = serial.Serial('/dev/cu.usbmodem14101', 115200)

    while True:
        msg = arduino_serial.readline().encode()
        receive_queue.append(msg)


serial_in = Queue()
serial_out = Queue()
serial_thread = Thread(target = serial_task, args = (serial_in, serial_out))
# arduino_serial = serial.Serial('/dev/cu.usbmodem14101', 115200)

@app.route("/serial")
def srl():
    val = serial_in.get(False)
    return val 

@app.route("/")
def dashboard():
    return render_template('dashboard.html')

@app.route("/chart-data")
def send_chart_data():
    timestamp = f'00:{random.randint(0, 59)}'
    water_level = random.randint(0, 300)
    water_level_data.append((timestamp, water_level))
    return water_level_data

@app.route("/status")
def status():
    return bridge_state

@app.route("/lights")
def lights():
    return lights_state

@app.route("/get-auto-manual")
def get_auto_manual():
    return str(manual_controls_enabled)

@app.route("/set-auto-manual", methods=["POST"])
def set_auto_manual():
    global manual_controls_enabled
    print(request.data.decode())
    if (request.data.decode() == 'true'):
        manual_controls_enabled = True
        print('Manual control enabled')
    elif (request.data.decode() == 'false'):
        manual_controls_enabled = False
        print('Manual control disabled')
    return Response(status = 200)

@app.route("/set-valve", methods=["POST"])
def set_valve():
    print (manual_controls_enabled)
    if (not manual_controls_enabled):
        return Response(status = 403)

    position = int(request.data.decode())
    if (position < 0 or position > 180):
        return Response(status = 422)

    print(f'Valve set to: {position}')
    return Response(status = 200)