from microbit import *
import time

while True:
    left = pin0.read_digital()
    right = pin1.read_digital()

    if (left == 1 and right == 1):
        pin13.write_digital(1) # Motor 1 Forward Direction
        pin14.write_digital(1) # PWM A
        pin15.write_digital(0) # Motor 2 Forward Direction
        pin16.write_digital(1) # PWM B

    elif (left == 0 and right == 1):
        pin13.write_digital(1) # Motor 1 Forward Direction
        pin14.write_digital(1) # PWM A
        pin15.write_digital(1) # Motor 2 Forward Direction
        pin16.write_digital(1) # PWM B

    elif (left == 1 and right == 0):
        pin13.write_digital(0) # Motor 1 Forward Direction
        pin14.write_digital(1) # PWM A
        pin15.write_digital(0) # Motor 2 Forward Direction
        pin16.write_digital(1) # PWM B