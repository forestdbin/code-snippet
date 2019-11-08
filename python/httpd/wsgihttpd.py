from wsgiref.simple_server import make_server, demo_app

def hello_world_app(environ, start_response):
    status = '200 OK'
    headers = [ ('Content-type', 'text/plain; charset=utf-8') ]
    start_response(status, headers)

    return [ b'hello, world.' ]

with make_server('', 8000, hello_world_app) as httpd:
# with make_server('', 8000, demo_app) as httpd:
    httpd.serve_forever()
