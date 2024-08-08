# start of k_motor.py
from microbit import *
import time

class KMotor:
    # Motor Directions
    FORWARD = 0
    REVERSE = 1

    # Motor Selectors
    MOTOR_1 = 0
    MOTOR_2 = 1

    def __init__(self):
        """
        Turn of both motors and clear the display
        """
        self.motor_off(KMotor.MOTOR_1)
        self.motor_off(KMotor.MOTOR_2)
        display.clear()

    def motor_on(self, motor, direction, speed=100):
        """
        Turn motor with the given direction and speed
        :param motor: KMotor.MOTOR1 or KMotor.Motor2
        :param direction: KMotor.FORWARD or KMOTOR.REVERSE
        :param speed: 0 - 100
        :return:
        """
        # make sure the speed is within range
        if not 0 <= speed <= 100:
            # not display a "NO" and return
            display.show(Image.NO)
            return

        # speed needs to be scaled from 0-100 to 0-1023
        speed = self._scale(speed)

        # Move Motor Forward
        if direction == KMotor.FORWARD:
            if motor == KMotor.MOTOR_1:
                pin14.write_analog(speed)
                pin13.write_digital(1)
            elif motor == KMotor.MOTOR_2:
                pin16.write_analog(speed)
                pin15.write_digital(0)

        # Move Motor In Reverse
        else:
            if motor == KMotor.MOTOR_1:
                pin14.write_analog(speed)
                pin13.write_digital(0)
            elif motor == KMotor.MOTOR_2:
                pin16.write_analog(speed)
                pin15.write_digital(1)

    def motor_off(self, motor):
        """
        Place motor in coast mode
        :param motor: KMotor.MOTOR1 or KMotor.Motor2
        :return:
        """
        if motor == KMotor.MOTOR_1:
            pin13.write_digital(0)
            pin14.write_analog(0)
        else:
            pin15.write_digital(0)
            pin16.write_analog(0)

    def motor_brake(self, motor):
        """
        Brake the selected motor.
        :param motor:
        :return:
        """
        if motor == KMotor.MOTOR_1:
            pin13.write_digital(1)
            pin14.write_analog(0)
        else:
            pin15.write_digital(0)
            pin16.write_analog(0)

    def _scale(self, value):
        """
        Scale the speed from 0-100 to 0-1023
        :param value: 0-100
        :return: scaled speed
        """
        new_value = (1023 / 100) * value
        return int(new_value)

# end of k_motory.py

#start of application

# application imports
#from microbit import sleep

# create an instance of KMotor
r = KMotor()

while True:
    if(pin0.read_analog() >= 500 and pin1.read_analog() >= 500):
       r.motor_on(r.MOTOR_1, r.FORWARD, 80)
       r.motor_on(r.MOTOR_2, r.FORWARD, 80)
