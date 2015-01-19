from flask import Flask
from flask import request
from flask import jsonify
from flask import render_template
import json
import concraft

server = concraft.Server()
port = server.get_port()
client = concraft.Client(port)
app = Flask(__name__)

@app.route('/')
def my_form():
    return render_template("form.html")

@app.route('/', methods=['POST'])
def my_form_post():
    sentence = request.form['text']
    decomposed = concraft.analyse(sentence, client)
    return json.dumps(decomposed, ensure_ascii = False)

if __name__ == '__main__':
    app.debug = True
    app.run()
