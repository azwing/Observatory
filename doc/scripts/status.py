#!/usr/bin/python3
#
# Status script for INDI Dome Scripting Gateway
#
# Arguments: file name to save current state and coordinates (parked ra dec)
# Exit code: 0 for success, 1 for failure
#

import sys
import logging
import serial

ser = serial.Serial('/dev/arduino', baudrate=9600, xonxoff=False, timeout=0.5)
result = ser.write(b':S#')
envoi = (ser.readline(None)).decode('ascii')
ser.close

logging.basicConfig(filename='/tmp/indilog', level=logging.DEBUG)

script, path = sys.argv

# debug file to watch status on user side
coordinates = open('/tmp/indi-status', 'w')
coordinates.truncate()
coordinates.write(envoi)
coordinates.close()

# write status in temp file that will be read by indi
status = open(path, 'w')
status.truncate()
status.write(envoi)
status.close()

logging.info('status: ' + envoi + ' : '+ path)

sys.exit(0)
