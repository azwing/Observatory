# Observatory

## Description
It is an attempt to control my Astronomical observatory.
The shelter is a cylindrical form with a flat roof with a sliding slit.
The full shelter sits on wheels so it can rotate CW / CCW without angular limit and is driven by a whind-screen Wiper motor.
To monitor the rotation, and encoder and a homing (North) limit switch are used.
The Roof Slit is still manual opening / closing but the project already includes motore control and limit switches management.

## hardware
- CPU: Arduino Mega Rev 3 board http://store.arduino.cc/products/arduino-mega-2560-rev3
- Rotation Motor Driver: Pololu 18V15 Brushed Motor Controller https://shop.watterott.com/Pololu-Simple-High-Power-Motor-Controller-18v15_1
- Roof Motor Driver: Pololu DRV8801 Single Motor Driver https://www.pololu.com/product/2136
- Encoder:  Ebay E38S6G5-600B-G24N 600 PPR encoder https://www.ebay.fr/itm/373778542043?var=642819752283
- a limit switch (Hall sensor) to synchronize the North position with the encoder making sure the encoder shows zéro at north.
- Push buttons for CW, CCW, Open, Close
- Selector Switch for Auto - Manu Selection
- Set of connectors for Power, Motors, Encoder 

## Functionalities
The Software I tested with is Indi with Kstars.
So Indi just sends the calulated angular position based on Telescope position.
Refer to Indi documentation https://www.indilib.org

Kstars communicates with driver via a set of Python scripts https://github.com/azwing/Observatory/tree/main/doc/scripts.
Kstars <==> Ekos <==> indi <==> dome_scripting <==> phython scripts <==> Arduino

The following functions are implemented:
**Manual mode:**
- Move East
- Move West
- Open Dome
- Close Dome

**Automatic Mode**
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

## Status
This is work in progress. I cannot be responsible of any damage due to the software / hardware described in here.

## Other Platforms
I am trying to port the software to BluePill and if successfull would like to create a dedicated PDB.
If anybody wants to help on the project you are wellcome.

## Licence
This project is under GNU GPL V3 https://www.gnu.org/licenses/gpl-3.0.en.html 
