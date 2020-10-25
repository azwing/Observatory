#!/usr/bin/python3
#
# Move counter clockwise script for INDI Dome Scripting Gateway
#
# Arguments: none
# Exit code: 0 for success, 1 for failure
#

import sys
import logging
import serial

ser = serial.Serial('/dev/arduino', baudrate=9600, xonxoff=False, timeout=0.5)
ser.write(b':MW#')
status = (ser.readline()).decode('ascii')
ser.close

logging.basicConfig(filename='/tmp/indilog', level=logging.DEBUG)
logging.info('moveccw: ' + status)

sys.exit(int(status))
