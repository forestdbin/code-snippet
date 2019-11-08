#!/usr/bin/python3

import cgi
import cgitb

cgitb.enable()

form = cgi.FieldStorage()

name = 'world'
if 'name' in form:
    name = form['name'].value.strip()
    if len(name) == 0:
        name = 'world'

print('Content-Type: text/html')
print()

print(f'''
<!doctype html>
<html lang='en'>
    <head> <title>hello</title> </head>
    <body> <p>hello, {name}. <br>
    <input type='button' value='Back' onclick='window.history.back();'> </body>
</html>
''')
