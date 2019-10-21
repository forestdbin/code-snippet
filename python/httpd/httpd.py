from socketserver import ThreadingMixIn
from http.server import HTTPServer
from http.server import CGIHTTPRequestHandler

if __name__ == '__main__':
    class ThreadingHTTPServer(ThreadingMixIn, HTTPServer):
        pass
    server_address = ('', 8000)
    CGIHTTPRequestHandler.cgi_directories.append('/bin')
    httpd = ThreadingHTTPServer(server_address, CGIHTTPRequestHandler)
    httpd.serve_forever()
