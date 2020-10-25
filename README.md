# Observatory
Observatory control system
It is an attemp to control my observatory.
I based the hardware on an Arduino Mega 1280 which is more than enough.
Ideally I would have developped it on a bluepill or so but had no harware available.
it is working with Kstars and indi with "Dome Scripting Gateway"
The scripts are under Doc

Kstars communicates with driver vis a set of Python scripts

Kstars <==> Ekos <==> indi <==> phython scripts <==> driver

The following functions are implemented:
Manual mode:
- Move East
- Move West
- Open Dome
- Close Dome

Automatic Mode
- Connect
- Disconnect
- Move East (East)
- Move CCW (West)
- Move To xxx.x (where xxx.x is azimuth in degrees)
- abort
- Open dome
- Close dome
- Park
- Unpark
- Status (returns P S A where P (Parked=1/Unparked=0), S (Opened=1/Closed=0), A xxx.x azimuth

and some additional debug serial commands to move directly things and calibrate the driver

This is work in progress. I cannot be responsible of any damage due to the software / hardware described in here.

