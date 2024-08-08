from microbit import *
import time

while True:
    left = pin0.read_digital()
    right = pin1.read_digital()

    display.scroll(right)
    display.clear()
    # display.scroll(right)