from flask import *

app = Flask(__name__)

@app.route("/")
def dashboard():
    return render_template('dashboard.html')
