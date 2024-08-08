from microbit import *
import time

while True:
    display.show(Image.HAPPY)
    time.sleep_ms(5000)
    display.show(Image.SAD)
    time.sleep_ms(5000)