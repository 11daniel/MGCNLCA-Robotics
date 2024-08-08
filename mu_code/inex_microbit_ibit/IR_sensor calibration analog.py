from microbit import *

left = pin13.read_analog()
right = pin15.read_analog()

while True:
    display.scroll("Left Sensor > ", str(left))
    sleep(5000)
    display.scroll("Right Sensor > ", str(right))
    sleep(5000)
