from flask import Flask, escape, request

app = Flask(__name__)

@app.route('/')
def hello():
    name = request.args.get('name', 'world')
    return f'hello, {escape(name)}.'
