from microbit import *
import time

while True:
    left = pin0.read_analog()
    right = pin1.read_analog()

    display.scroll(right)
    display.clear()