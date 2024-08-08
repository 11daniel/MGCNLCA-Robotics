from microbit import *
import time

while True:
    display.scroll(pin0.analog_read)
    time.sleep_ms(100)