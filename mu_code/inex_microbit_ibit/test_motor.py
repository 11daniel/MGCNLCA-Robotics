from microbit import *
import time


motor.init()
speed = 255

while True:
    motor.runSpeed(1, 100)
    motor.runSpeed(2, 100)
    time.sleep_ms(5000)

    motor.runSpeed(1, -100)
    motor.runSpeed(2, -100)
    time.sleep_ms(5000)