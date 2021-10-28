'''
alpha blend demo, tested with Python 3.8.10 on Ubuntu
'''

import tkinter as tk
from tkinter import ttk

def color_to_string(color):
    return '#' + \
            format(color[0], '02x') + \
            format(color[1], '02x') + \
            format(color[2], '02x')

def alpha_blend(colorA, colorB, alpha):
    return [
            (colorA[0] * alpha + colorB[0] * (255 - alpha)) // 255,
            (colorA[1] * alpha + colorB[1] * (255 - alpha)) // 255,
            (colorA[2] * alpha + colorB[2] * (255 - alpha)) // 255,
            ]

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.create_formula()
        self.create_canvas()
        self.create_input()
        self.draw_canvas()

    def create_formula(self):
        self.formula_image = tk.PhotoImage(file='formula.png')
        self.formula_image_label = ttk.Label(
                self,
                image=self.formula_image,
                padding=5)
        self.formula_image_label.grid(row=0, columnspan=3)

    def create_canvas(self):
        self.canvas = tk.Canvas(self, width=400, height=400)
        self.canvas.grid(rowspan=4, column=0)

    def create_input(self):
        self.red_label = tk.Label(self, text='Red: ')
        self.red_label.grid(row=1, column=1)

        self.red_value = tk.IntVar(self, value=0)
        self.red_value.trace_add('write',
                lambda v, i, m: self.draw_canvas())
        self.red_entry = tk.Entry(self, textvariable=self.red_value)
        self.red_entry.grid(row=1, column=2)

        self.green_label = tk.Label(self, text='Green: ')
        self.green_label.grid(row=2, column=1)

        self.green_value = tk.IntVar(self, value=0)
        self.green_value.trace_add('write',
                lambda v, i, m: self.draw_canvas())
        self.green_entry = tk.Entry(self, textvariable=self.green_value)
        self.green_entry.grid(row=2, column=2)

        self.blue_label = tk.Label(self, text='Blue: ')
        self.blue_label.grid(row=3, column=1)

        self.blue_value = tk.IntVar(self, value=0)
        self.blue_value.trace_add('write',
                lambda v, i, m: self.draw_canvas())
        self.blue_entry = tk.Entry(self, textvariable=self.blue_value)
        self.blue_entry.grid(row=3, column=2)

        self.alpha_label = tk.Label(self, text='Alpha: ')
        self.alpha_label.grid(row=4, column=1)

        self.alpha_value = tk.IntVar(self, value=255)
        self.alpha_value.trace_add('write',
                lambda v, i, m: self.draw_canvas())
        self.alpha_entry = tk.Entry(self, textvariable=self.alpha_value)
        self.alpha_entry.grid(row=4, column=2)

    def draw_canvas(self):
        try:
            self.draw_canvas_internal([
                self.red_value.get(),
                self.green_value.get(),
                self.blue_value.get(),
                ],
                self.alpha_value.get())
        except:
            pass

    def draw_canvas_internal(self, over_color, alpha):
        colors = [
                [ 0, 0, 0, ],
                [ 255, 0, 0, ],
                [ 0, 255, 0, ],
                [ 0, 0, 255, ],
                [ 255, 255, 0, ],
                [ 0, 255, 255, ],
                [ 255, 0, 255, ],
                [ 255, 255, 255, ],
                [ 63, 63, 63, ],
                [ 255, 127, 127, ],
                [ 127, 255, 127, ],
                [ 127, 127, 255, ],
                [ 255, 255, 127, ],
                [ 127, 255, 255, ],
                [ 255, 127, 255, ],
                [ 191, 191, 191, ],
                ]
        for i, color in enumerate(colors):
            x, y = i % 4 * 100, i // 4 * 100
            self.canvas.create_rectangle(x, y, x + 100, y + 100,
                    fill=color_to_string(alpha_blend(over_color, color, alpha)),
                    outline=color_to_string(alpha_blend(over_color, color, alpha)))

root = tk.Tk()
root.geometry('700x500')
root.title('Alpha Blending')

app = Application(master=root)
app.mainloop()
