EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Observatory controller, connectors and Devices"
Date "2019-04-13"
Rev "0"
Comp ""
Comment1 "AZConcept"
Comment2 "F67390 Schoenau"
Comment3 "3 rue des bateliers"
Comment4 "Alain Zwingelstein"
$EndDescr
$Comp
L Motor:Motor_DC M1
U 1 1 5CCBE008
P 4300 1250
F 0 "M1" H 4458 1246 50  0000 L CNN
F 1 "Motor_DC" H 4458 1155 50  0000 L CNN
F 2 "" H 4300 1160 50  0001 C CNN
F 3 "~" H 4300 1160 50  0001 C CNN
	1    4300 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector:DIN-3 J1
U 1 1 5CCBE175
P 1900 1300
F 0 "J1" V 2300 1300 50  0000 R CNN
F 1 "DIN-3-F" V 2300 1150 50  0000 R CNN
F 2 "" H 1900 1300 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 1900 1300 50  0001 C CNN
	1    1900 1300
	0    -1   -1   0   
$EndComp
$Comp
L Connector:DIN-3 J6
U 1 1 5CCBE1D6
P 2900 1300
F 0 "J6" V 3300 1300 50  0000 R CNN
F 1 "DIN-3 M" V 3300 1700 50  0000 R CNN
F 2 "" H 2900 1300 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 2900 1300 50  0001 C CNN
	1    2900 1300
	0    1    -1   0   
$EndComp
Wire Wire Line
	2900 1000 4300 1000
Wire Wire Line
	4300 1000 4300 1050
Wire Wire Line
	2900 1600 4300 1600
Wire Wire Line
	4300 1600 4300 1550
$Comp
L power:Earth #PWR0105
U 1 1 5CCBE27D
P 4050 1300
F 0 "#PWR0105" H 4050 1050 50  0001 C CNN
F 1 "Earth" H 4050 1150 50  0001 C CNN
F 2 "" H 4050 1300 50  0001 C CNN
F 3 "~" H 4050 1300 50  0001 C CNN
	1    4050 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1300 4050 1300
Wire Wire Line
	1900 1000 1250 1000
Wire Wire Line
	1600 1300 1250 1300
Wire Wire Line
	1900 1600 1250 1600
$Comp
L observatoire:Encoder G?
U 1 1 5CD178E6
P 4150 2400
AR Path="/5CD178E6" Ref="G?"  Part="1" 
AR Path="/5CCBDB9F/5CD178E6" Ref="G1"  Part="1" 
F 0 "G1" H 4150 2650 50  0000 R CNN
F 1 "Encoder" H 4250 2150 50  0000 R CNN
F 2 "" H 4150 2400 50  0001 C CNN
F 3 "" H 4150 2400 50  0001 C CNN
	1    4150 2400
	-1   0    0    1   
$EndComp
$Comp
L Connector:6P6C J?
U 1 1 5CD178EE
P 1950 2350
AR Path="/5CD178EE" Ref="J?"  Part="1" 
AR Path="/5CCBDB9F/5CD178EE" Ref="J2"  Part="1" 
F 0 "J2" H 1950 2000 50  0000 R CNN
F 1 "RJ11" H 1620 2445 50  0001 R CNN
F 2 "" V 1950 2375 50  0001 C CNN
F 3 "~" V 1950 2375 50  0001 C CNN
	1    1950 2350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Male J?
U 1 1 5CD178F5
P 2750 2350
AR Path="/5CD178F5" Ref="J?"  Part="1" 
AR Path="/5CCBDB9F/5CD178F5" Ref="J4"  Part="1" 
F 0 "J4" H 2856 2637 50  0000 C CNN
F 1 "RJ11" H 2856 2637 50  0001 C CNN
F 2 "" H 2750 2350 50  0001 C CNN
F 3 "~" H 2750 2350 50  0001 C CNN
	1    2750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2250 3750 2150
Wire Wire Line
	3750 2450 3500 2450
Wire Wire Line
	3500 2450 3500 2650
Wire Wire Line
	3500 2650 2950 2650
Wire Wire Line
	2950 2450 3400 2450
Wire Wire Line
	3400 2450 3400 2550
Wire Wire Line
	3400 2550 3750 2550
Wire Wire Line
	3750 2350 2950 2350
Text HLabel 1250 1000 0    50   Input ~ 0
Mot+
Text HLabel 1250 1600 0    50   Input ~ 0
Mot-
Text HLabel 1250 2450 0    50   Input ~ 0
Enc+
Text HLabel 1250 2350 0    50   Input ~ 0
EncA
Text HLabel 1250 2650 0    50   Input ~ 0
EncB
Text HLabel 1250 1300 0    50   Input ~ 0
Gnd
Text HLabel 1250 2150 0    50   Input ~ 0
Gnd
Wire Wire Line
	2950 2150 3750 2150
Text HLabel 1150 3700 0    50   Input ~ 0
Gnd
Wire Wire Line
	1250 2150 1550 2150
Wire Wire Line
	1250 2350 1550 2350
Wire Wire Line
	1250 2450 1550 2450
Wire Wire Line
	1250 2650 1550 2650
Text HLabel 1150 3100 0    50   Input ~ 0
Index
Text HLabel 1150 3200 0    50   Input ~ 0
Roof_Open
Text HLabel 1150 3300 0    50   Input ~ 0
Roof_Close
Text HLabel 1150 3400 0    50   Input ~ 0
Sync
Text HLabel 1150 3500 0    50   Input ~ 0
Spare_In1
$Comp
L Switch:SW_Push_Open SW10
U 1 1 5CDC8770
P 3800 3150
F 0 "SW10" H 3550 3200 50  0000 C CNN
F 1 "Roof_Opened" H 4350 3150 50  0000 C CNN
F 2 "" H 3800 3350 50  0001 C CNN
F 3 "~" H 3800 3350 50  0001 C CNN
	1    3800 3150
	1    0    0    1   
$EndComp
$Comp
L Switch:SW_Push_Open SW9
U 1 1 5CDC9061
P 3800 3000
F 0 "SW9" H 3550 3050 50  0000 C CNN
F 1 "Index" H 4200 3000 50  0000 C CNN
F 2 "" H 3800 3200 50  0001 C CNN
F 3 "~" H 3800 3200 50  0001 C CNN
	1    3800 3000
	1    0    0    1   
$EndComp
$Comp
L Switch:SW_Push_Open SW13
U 1 1 5CDC96E9
P 3800 3600
F 0 "SW13" H 3550 3650 50  0000 C CNN
F 1 "N/C" H 4200 3600 50  0000 C CNN
F 2 "" H 3800 3800 50  0001 C CNN
F 3 "~" H 3800 3800 50  0001 C CNN
	1    3800 3600
	1    0    0    1   
$EndComp
$Comp
L Switch:SW_Push_Open SW12
U 1 1 5CDC96F0
P 3800 3450
F 0 "SW12" H 3550 3500 50  0000 C CNN
F 1 "Sync" H 4200 3450 50  0000 C CNN
F 2 "" H 3800 3650 50  0001 C CNN
F 3 "~" H 3800 3650 50  0001 C CNN
	1    3800 3450
	1    0    0    1   
$EndComp
$Comp
L Switch:SW_Push_Open SW11
U 1 1 5CDC9C2B
P 3800 3300
F 0 "SW11" H 3550 3350 50  0000 C CNN
F 1 "Roof_Closed" H 4350 3300 50  0000 C CNN
F 2 "" H 3800 3500 50  0001 C CNN
F 3 "~" H 3800 3500 50  0001 C CNN
	1    3800 3300
	1    0    0    1   
$EndComp
$Comp
L Motor:Motor_DC M2
U 1 1 5CDD0422
P 4050 4950
F 0 "M2" H 4208 4946 50  0000 L CNN
F 1 "Motor_DC" H 4208 4855 50  0000 L CNN
F 2 "" H 4050 4860 50  0001 C CNN
F 3 "~" H 4050 4860 50  0001 C CNN
	1    4050 4950
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic_Shielded:Conn_01x05_Shielded J5
U 1 1 5CDD3886
P 1900 3300
F 0 "J5" H 1900 3600 50  0000 L CNN
F 1 "DIN5 Male" H 1900 3700 50  0000 L CNN
F 2 "" H 1900 3300 50  0001 C CNN
F 3 "~" H 1900 3300 50  0001 C CNN
	1    1900 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic_Shielded:Conn_01x05_Shielded J9
U 1 1 5CDD545D
P 2850 3300
F 0 "J9" H 2850 3600 50  0000 C CNN
F 1 "DIN5 Fem" H 2700 3700 50  0000 C CNN
F 2 "" H 2850 3300 50  0001 C CNN
F 3 "~" H 2850 3300 50  0001 C CNN
	1    2850 3300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1700 3100 1150 3100
Wire Wire Line
	1700 3200 1150 3200
Wire Wire Line
	1700 3300 1150 3300
Wire Wire Line
	1700 3400 1150 3400
Wire Wire Line
	1700 3500 1150 3500
Wire Wire Line
	1900 3700 1150 3700
Wire Wire Line
	3050 3600 3050 3500
Wire Wire Line
	3050 3450 3050 3400
Wire Wire Line
	3050 3000 3050 3100
Wire Wire Line
	3050 3150 3050 3200
Wire Wire Line
	4000 3600 4050 3600
Wire Wire Line
	4050 3600 4050 3450
Wire Wire Line
	4050 3000 4000 3000
Wire Wire Line
	4000 3150 4050 3150
Connection ~ 4050 3150
Wire Wire Line
	4050 3150 4050 3000
Wire Wire Line
	4000 3300 4050 3300
Connection ~ 4050 3300
Wire Wire Line
	4050 3300 4050 3150
Wire Wire Line
	4000 3450 4050 3450
Connection ~ 4050 3450
Wire Wire Line
	4050 3450 4050 3300
Text HLabel 1150 4950 0    50   Input ~ 0
Gnd
$Comp
L Connector_Generic_Shielded:Conn_01x05_Shielded J7
U 1 1 5CDF6E10
P 1900 4550
F 0 "J7" H 1900 4850 50  0000 L CNN
F 1 "DIN5 Male" H 1900 4950 50  0000 L CNN
F 2 "" H 1900 4550 50  0001 C CNN
F 3 "~" H 1900 4550 50  0001 C CNN
	1    1900 4550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic_Shielded:Conn_01x05_Shielded J10
U 1 1 5CDF6E17
P 2850 4550
F 0 "J10" H 2850 4850 50  0000 C CNN
F 1 "DIN5 Fem" H 2700 4950 50  0000 C CNN
F 2 "" H 2850 4550 50  0001 C CNN
F 3 "~" H 2850 4550 50  0001 C CNN
	1    2850 4550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1700 4350 1150 4350
Wire Wire Line
	1700 4450 1150 4450
Wire Wire Line
	1700 4550 1150 4550
Wire Wire Line
	1700 4650 1150 4650
Wire Wire Line
	1700 4750 1150 4750
Wire Wire Line
	1900 4950 1150 4950
Text HLabel 1150 4750 0    50   Input ~ 0
M_Roof+
Text HLabel 1150 4650 0    50   Input ~ 0
M_Roof-
Text HLabel 1150 4350 0    50   Input ~ 0
Light
Text HLabel 1150 4450 0    50   Input ~ 0
Siren
Text HLabel 1150 4550 0    50   Input ~ 0
Moving
Wire Wire Line
	3050 4650 4050 4650
Wire Wire Line
	3050 4750 3050 5150
Wire Wire Line
	3050 5150 4050 5150
Text HLabel 1150 6400 0    50   Input ~ 0
Gnd
$Comp
L Connector_Generic_Shielded:Conn_01x05_Shielded J8
U 1 1 5CE0E4B0
P 1900 6000
F 0 "J8" H 1900 6300 50  0000 L CNN
F 1 "DIN5 Male" H 1900 6400 50  0000 L CNN
F 2 "" H 1900 6000 50  0001 C CNN
F 3 "~" H 1900 6000 50  0001 C CNN
	1    1900 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5800 1150 5800
Wire Wire Line
	1700 5900 1150 5900
Wire Wire Line
	1700 6000 1150 6000
Wire Wire Line
	1700 6100 1150 6100
Wire Wire Line
	1700 6200 1150 6200
Wire Wire Line
	1900 6400 1150 6400
Text HLabel 1150 6200 0    50   Input ~ 0
Out_spare1
Text HLabel 1150 6100 0    50   Input ~ 0
Out_spare2
Text HLabel 1150 5800 0    50   Input ~ 0
Out_spare5
Text HLabel 1150 5900 0    50   Input ~ 0
Out_spare4
Text HLabel 1150 6000 0    50   Input ~ 0
Out_spare3
$Comp
L Device:Buzzer BZ1
U 1 1 5CE0FF58
P 5400 4550
F 0 "BZ1" H 5553 4579 50  0000 L CNN
F 1 "Buzzer" H 5553 4488 50  0000 L CNN
F 2 "" V 5375 4650 50  0001 C CNN
F 3 "~" V 5375 4650 50  0001 C CNN
	1    5400 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5CE10160
P 4050 4350
F 0 "D2" H 4200 4300 50  0000 C CNN
F 1 "Light" H 3750 4300 50  0000 C CNN
F 2 "" H 4050 4350 50  0001 C CNN
F 3 "~" H 4050 4350 50  0001 C CNN
	1    4050 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 5CE10236
P 4050 4550
F 0 "D3" H 4200 4500 50  0000 C CNN
F 1 "Moving" H 3700 4500 50  0000 C CNN
F 2 "" H 4050 4550 50  0001 C CNN
F 3 "~" H 4050 4550 50  0001 C CNN
	1    4050 4550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4200 4350 4650 4350
Wire Wire Line
	4650 4350 4650 4550
Wire Wire Line
	4650 4650 5300 4650
Wire Wire Line
	4200 4550 4650 4550
Connection ~ 4650 4550
Wire Wire Line
	4650 4550 4650 4650
Wire Wire Line
	2850 4950 2850 5250
Wire Wire Line
	2850 5250 4650 5250
Wire Wire Line
	4650 5250 4650 4650
Connection ~ 4650 4650
$Comp
L Device:R R1
U 1 1 5CE20833
P 3750 4350
F 0 "R1" V 3700 4150 50  0000 C CNN
F 1 "1K" V 3750 4350 50  0000 C CNN
F 2 "" V 3680 4350 50  0001 C CNN
F 3 "~" H 3750 4350 50  0001 C CNN
	1    3750 4350
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CE20936
P 3750 4550
F 0 "R2" V 3700 4350 50  0000 C CNN
F 1 "1K" V 3750 4550 50  0000 C CNN
F 2 "" V 3680 4550 50  0001 C CNN
F 3 "~" H 3750 4550 50  0001 C CNN
	1    3750 4550
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CE225AB
P 5150 4450
F 0 "R3" V 5100 4250 50  0000 C CNN
F 1 "1K" V 5150 4450 50  0000 C CNN
F 2 "" V 5080 4450 50  0001 C CNN
F 3 "~" H 5150 4450 50  0001 C CNN
	1    5150 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 4350 3050 4350
Wire Wire Line
	3600 4550 3050 4550
Wire Wire Line
	3050 4450 5000 4450
Wire Wire Line
	2850 3700 4050 3700
Wire Wire Line
	4050 3700 4050 3600
Connection ~ 4050 3600
Wire Wire Line
	3050 3000 3600 3000
Wire Wire Line
	3050 3150 3600 3150
Wire Wire Line
	3050 3300 3600 3300
Wire Wire Line
	3050 3450 3600 3450
Wire Wire Line
	3050 3600 3600 3600
Text Notes 2500 3550 0    50   ~ 0
Blanc\nGris\nJaune\nOrange\nBleu C\nBleu 
$EndSCHEMATC
