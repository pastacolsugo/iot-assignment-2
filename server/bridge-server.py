from flask import *
from datetime import datetime
import random
import serial
import requests
import datetime
from queue import Queue
import platform

app = Flask(__name__)

water_level_data = []

control = 'auto'
control_source = 'disabled'
valve_position = 0
bridge_state = 'normal'
lights_state = 'off'
SERIAL_ENABLE = True

if platform.system() == 'Darwin':
    arduino_serial_port = '/dev/cu.usbmodem14101'
elif platform.system() == 'Windows':
    arduino_serial_port = 'COM1' # ?
baud_rate = 115200

arduino_serial = serial.Serial(arduino_serial_port, 115200) if SERIAL_ENABLE else 0
serial_out_queue = Queue()
serial_in_buffer = ""
serial_lock = False

def parse_serial_message(msg):
    global bridge_state
    global lights_state
    global water_level_data
    global valve_position
    global control
    global control_source

    if not ':' in msg:
        return
    print(msg)
    key, value = msg.split(':')
    value = value.strip()
    if key == 'state':
        if value == 'normal':
            bridge_state = 'normal'
        elif value == 'prealarm':
            bridge_state = 'prealarm'
        elif value == 'alarm':
            bridge_state = 'alarm'
        else:
            print(f'SERIAL ERROR: Invalid status value {value}')
        return

    if key == 'lamp':
        if value == 'on':
            lights_state = 'on'
        elif value == 'off':
            lights_state = 'off'
        else:
            print(f'SERIAL ERROR: Invalid light value {value}')
        return

    if key == 'water_level':
        t = str(datetime.datetime.now()).split(' ')[1].split('.')[0]
        wl = int(value)
        water_level_data.append((t, wl))

    if key == 'valve_position':
        valve_position = int(value)

    if key == 'control':
        control = value

    if key == 'control_source':
        control_source = value

def serial_task():
    if not SERIAL_ENABLE:
        return
    global serial_lock
    if serial_lock:
        return
    serial_lock = True
    global serial_in_buffer
    while arduino_serial.in_waiting > 0:      
        msg = arduino_serial.read(arduino_serial.in_waiting).decode()
        print(f'Serial received {msg}')
        serial_in_buffer += msg
        while '\n' in serial_in_buffer:
            msg = serial_in_buffer.split('\n')[0]
            serial_in_buffer = '\n'.join(serial_in_buffer.split('\n')[1:])
            parse_serial_message(msg)

    if not serial_out_queue.empty():
        while not serial_out_queue.empty():
            msg = serial_out_queue.get()
            arduino_serial.write(str.encode(msg))
        arduino_serial.flush()
    serial_lock = False

def serial_set_control(control):
    if control == 'auto':
        serial_out_queue.put('set_control:auto')
    if control == 'manual':
        serial_out_queue.put('set_control:manual')
    serial_task()

def serial_set_valve(pos):
    if pos < 0:
        pos = 0
    if pos > 180:
        pos = 180
    serial.serial_out_queue.put(f'set_valve:{str(pos)}')
    serial_task()

# @app.route("/serial")
# def srl():
#     if not serial_in.empty():
#         messages = []
#         while not serial_in.empty():
#             msg = serial_in.read_until().decode()
#             messages.append(msg)
#         return Response(messages)
#     return Response(status=204)

@app.route("/")
def dashboard():
    return render_template('dashboard.html')

@app.route("/chart-data")
def send_chart_data():
    # timestamp = f'00:{random.randint(0, 59)}'
    # water_level = random.randint(0, 300)
    # water_level_data.append((timestamp, water_level))
    return water_level_data

@app.route("/status")
def status():
    serial_task()
    return bridge_state

@app.route("/lights")
def lights():
    serial_task()
    return lights_state

@app.route("/get-auto-manual")
def get_auto_manual():
    serial_task()
    return control

@app.route("/set-auto-manual", methods=["POST"])
def set_auto_manual():
    serial_task()
    global control
    global control_source
    print(request.data.decode())

    if (request.data.decode() == 'manual'):
        control = 'manual'
        control_source = 'serial'
        serial_set_control('manual')
        print('Manual control enabled')

    elif (request.data.decode() == 'auto'):
        control = 'auto'
        control_source = 'disabled'
        serial_set_control('auto')
        print('Manual control disabled')

    serial_task()
    return Response(status = 200)

@app.route("/set-valve", methods=["POST"])
def set_valve():
    serial_task()
    if (not control == 'manual'):
        return Response(status = 403)

    position = int(request.data.decode())
    if (position < 0 or position > 180):
        return Response(status = 422)

    serial_set_valve(position)
    serial_task()
    print(f'Valve set to: {position}')
    return Response(status = 200)