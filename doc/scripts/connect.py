#!/usr/bin/python3
#
# Connect script for INDI Dome Scripting Gateway
#
# Arguments: none
# Exit code: 0 for success, 1 for failure
#

import sys
import logging
import time
import serial

# just open arduino serial and set DTR so no more reset on serial.open
import termios
port = '/dev/arduino'
f = open(port)
attrs = termios.tcgetattr(f)
attrs[2] = attrs[2] & ~termios.HUPCL
termios.tcsetattr(f, termios.TCSAFLUSH, attrs)
f.close()

ser = serial.Serial('/dev/arduino', baudrate=9600, xonxoff=False, timeout=0.5)
ser.write(b'\x06')
status = (ser.read()).decode('ascii')
ser.close

logging.basicConfig(filename='/tmp/indilog', level=logging.DEBUG)
logging.info('connecting: ' + status)

# create a debug file , will be update by status.py
coordinates = open('/tmp/indi-status', 'w')
coordinates.truncate()
coordinates.write('1 0 0')
coordinates.close()

sys.exit(int(status))
