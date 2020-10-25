#!/usr/bin/python3
#
# Goto azimuth script for INDI Dome Scripting Gateway
#
# Arguments: Az
# Exit code: 0 for success, 1 for failure
#

import sys
import logging
import serial

script, az = sys.argv

ser = serial.Serial('/dev/arduino', baudrate=9600, xonxoff=False, timeout=0.5)
envoi=':GT' + az + '#' 
ser.write(bytes(envoi,'ascii'))
status = (ser.readline()).decode('ascii')
ser.close

logging.basicConfig(filename='/tmp/indilog', level=logging.DEBUG)
logging.info('goto:=>>> ' + az + ' ' + status) 

sys.exit(int(status))
