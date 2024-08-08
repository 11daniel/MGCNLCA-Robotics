from microbit import *
import time

while True:
    left = pin0.read_analog()

    display.scroll(left, 200)
