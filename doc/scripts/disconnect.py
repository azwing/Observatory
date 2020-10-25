#!/usr/bin/python3
#
# DisConnect script for INDI Dome Scripting Gateway
#
# Arguments: none
# Exit code: 0 for success, 1 for failure
#

import sys
import logging
import serial

ser = serial.Serial('/dev/arduino', baudrate=9600, xonxoff=False, timeout=0.5)
ser.write(b':Q#')
status = (ser.read()).decode('ascii')
ser.close

logging.basicConfig(filename='/tmp/indilog', level=logging.DEBUG)
logging.info('disconnect: ' + status)

sys.exit(int(status))
