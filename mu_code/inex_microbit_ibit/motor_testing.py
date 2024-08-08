from microbit import *
import time

# Pins for motor 1 left - P13, P14
# Pins for motor 2 - right - P16, P15

while True:

    pin13.write_digital(1)  # Motor 1 Forward Direction
    pin14.write_digital(1)  # PWM A

    pin15.write_digital(0)  # Motor 2 Forward Direction
    pin16.write_digital(1)  # PWM B
    time.sleep_ms(2000)

    pin13.write_digital(0)  # Motor 1 Reverse Direction
    pin14.write_digital(1)  # PWM A

    pin15.write_digital(1)  # Motor 2 Reverse Direction
    pin16.write_digital(1)  # PWM B
    time.sleep_ms(2000)

    pin13.write_digital(1)  # Motor 1 Right Direction
    pin14.write_digital(0)  # PWM A

    pin15.write_digital(0)  # Motor 2 Right Direction
    pin16.write_digital(1)  # PWM B
    time.sleep_ms(2000)

    pin13.write_digital(1)  # Motor 1 Left Direction
    pin14.write_digital(1)  # PWM A

    pin15.write_digital(0)  # Motor 2 Left Direction
    pin16.write_digital(0)  # PWM B
    time.sleep_ms(2000)