# Triacs-Control

This block allows:

     1. smoothly run the load connected to the network 220 volts 50 Hz;
     2. regulate the power, with the help of the opening time of the triac;
     3. measure current.


R5, R6, R7, VO1: transition sensor through 0, with each transition through 0 generates a pulse.

R12 - R15, Q1, VO2: circuit for opening the triac with inverter.

R16, C5: snubber.

U2, C3, C4: current sensor.

R8 - R11, S2, S3: Triac control buttons.

U1, C6 - C8: power selection (built-in or USB)

R4, C9, S1: reset

J1, U4, R17, R18: connection scheme via USB.

The OLED screen of the SSD1306 is connected to the I2C1 bus.

C1,C2.                                0805 20pF

C3.                                   0805 0.1uF

C4.                                   0805 1nF

C5.                                   2220 10nF >220V

C6.                                   10uF >6.3V electrolition

C7 - C9                               0805 0.1 uF

D1.                                   BTB24-600

D2.                                   Led 0805

R1 - R3, R5, R8 - R9, R12 - R14       0805 510

R4, R10, R11                          0805 10k

R6, R7.                               33k 1W

R15                                   180 1W

R16                                   100 0.25W

R17, R18.                             0805 22

U1.                                   1117 3,3V SOT223

U2.                                   ACS712-20

U3.                                   STM32F103C8T6

U4.                                   TPD2E001DRLR

Q1.                                   BC847B

VO1.                                  PC814

VO2.                                  MOC3020

J1.                                   miniUSB or microUSB

Y1.                                   8MHz
