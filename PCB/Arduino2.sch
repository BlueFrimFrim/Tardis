EESchema Schematic File Version 2
LIBS:Tardis-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Tardis
LIBS:Tardis-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
Title "T.A.R.D.I.S"
Date "2017-12-04"
Rev "3"
Comp "Altcom"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4300 5250 3    60   BiDi ~ 0
SDA
Text HLabel 4450 5250 3    60   BiDi ~ 0
SCL
Text HLabel 5400 3200 2    60   BiDi ~ 0
2
Text HLabel 5400 3350 2    60   BiDi ~ 0
3
Text HLabel 5400 3500 2    60   BiDi ~ 0
4
Text HLabel 5400 3650 2    60   BiDi ~ 0
5
Text HLabel 5400 3800 2    60   BiDi ~ 0
6
Text HLabel 5400 3950 2    60   BiDi ~ 0
7
Text HLabel 5400 4100 2    60   BiDi ~ 0
8
Text HLabel 5400 4250 2    60   BiDi ~ 0
9
Text HLabel 5400 4400 2    60   BiDi ~ 0
10
Text HLabel 5400 4550 2    60   BiDi ~ 0
11
Text HLabel 5400 4700 2    60   BiDi ~ 0
12
Text HLabel 5400 4850 2    60   BiDi ~ 0
13
Text HLabel 3375 4100 0    60   BiDi ~ 0
RST
$Comp
L C C12
U 1 1 5A16C124
P 3150 3525
F 0 "C12" H 3175 3625 50  0000 L CNN
F 1 "0.1uF" H 3175 3425 50  0000 L CNN
F 2 "" H 3188 3375 50  0001 C CNN
F 3 "" H 3150 3525 50  0001 C CNN
	1    3150 3525
	1    0    0    -1  
$EndComp
$Comp
L Header1 H5
U 1 1 5A16C164
P 4375 2350
F 0 "H5" H 4275 2450 60  0000 C CNN
F 1 "Header1" H 4375 2375 60  0001 C CNN
F 2 "Footprints:Pin_Header_Straight_1x06_Pitch2.54mm" H 4375 2350 60  0001 C CNN
F 3 "" H 4375 2350 60  0001 C CNN
	1    4375 2350
	1    0    0    -1  
$EndComp
$Comp
L Arduino-Pro-5V U5
U 1 1 5A16C1FD
P 5050 3600
F 0 "U5" H 4500 3100 60  0000 C CNN
F 1 "Arduino-Pro-5V" H 4550 2950 60  0000 C CNN
F 2 "Footprints:ArduinoMINIPRO" H 5350 3400 60  0001 C CNN
F 3 "" H 5350 3400 60  0001 C CNN
	1    5050 3600
	1    0    0    -1  
$EndComp
NoConn ~ 3700 3200
NoConn ~ 3700 3450
NoConn ~ 3700 3525
Wire Wire Line
	4175 2800 4175 2450
Wire Wire Line
	4275 2450 4275 2800
Wire Wire Line
	4375 2800 4375 2450
Wire Wire Line
	4475 2450 4475 2800
Wire Wire Line
	4575 2800 4575 2450
Wire Wire Line
	4700 2450 4700 2800
Wire Wire Line
	3150 3325 3150 3375
Connection ~ 3150 3350
Wire Wire Line
	3150 3700 3150 3675
Wire Wire Line
	3700 3650 3675 3650
Wire Wire Line
	3675 3650 3675 3750
Wire Wire Line
	3675 3725 3700 3725
Connection ~ 3675 3725
Wire Wire Line
	3700 4200 3675 4200
Wire Wire Line
	3675 4200 3675 4100
Wire Wire Line
	3375 4100 3700 4100
Connection ~ 3675 4100
Wire Wire Line
	3700 4800 3675 4800
Wire Wire Line
	3675 4350 3675 4825
Wire Wire Line
	3675 4350 3700 4350
Wire Wire Line
	3700 4500 3675 4500
Connection ~ 3675 4500
Wire Wire Line
	3700 4650 3675 4650
Connection ~ 3675 4650
Connection ~ 3675 4800
Wire Wire Line
	4600 5150 4600 5175
Wire Wire Line
	4600 5175 4750 5175
Wire Wire Line
	4750 5175 4750 5150
Wire Wire Line
	4675 5200 4675 5175
Connection ~ 4675 5175
Wire Wire Line
	4300 5150 4300 5250
Wire Wire Line
	4450 5250 4450 5150
Wire Wire Line
	5300 4400 5400 4400
Wire Wire Line
	5400 4250 5300 4250
Wire Wire Line
	5300 4100 5400 4100
Wire Wire Line
	5300 3950 5400 3950
Wire Wire Line
	5300 3800 5400 3800
Wire Wire Line
	5400 3650 5300 3650
Wire Wire Line
	5300 3500 5400 3500
Wire Wire Line
	5400 3350 5300 3350
Wire Wire Line
	5300 3200 5400 3200
Text HLabel 2225 2625 0    60   Input ~ 0
GND
$Comp
L GND-RESCUE-Tardis #PWR42
U 1 1 5A320A72
P 2375 2650
F 0 "#PWR42" H 2375 2400 50  0001 C CNN
F 1 "GND" H 2375 2500 50  0001 C CNN
F 2 "" H 2375 2650 50  0001 C CNN
F 3 "" H 2375 2650 50  0001 C CNN
	1    2375 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2225 2625 2375 2625
Wire Wire Line
	2375 2625 2375 2650
$Comp
L +5V #PWR41
U 1 1 5A320A7A
P 2375 2500
F 0 "#PWR41" H 2375 2350 50  0001 C CNN
F 1 "+5V" H 2375 2640 50  0000 C CNN
F 2 "" H 2375 2500 50  0001 C CNN
F 3 "" H 2375 2500 50  0001 C CNN
	1    2375 2500
	1    0    0    -1  
$EndComp
Text HLabel 2225 2525 0    60   Input ~ 0
5V
Wire Wire Line
	2225 2525 2375 2525
Wire Wire Line
	2375 2525 2375 2500
$Comp
L +5V #PWR43
U 1 1 5A320C5D
P 3150 3325
F 0 "#PWR43" H 3150 3175 50  0001 C CNN
F 1 "+5V" H 3150 3465 50  0000 C CNN
F 2 "" H 3150 3325 50  0001 C CNN
F 3 "" H 3150 3325 50  0001 C CNN
	1    3150 3325
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 3350 3700 3350
$Comp
L GND-RESCUE-Tardis #PWR44
U 1 1 5A320D7F
P 3150 3700
F 0 "#PWR44" H 3150 3450 50  0001 C CNN
F 1 "GND" H 3150 3550 50  0001 C CNN
F 2 "" H 3150 3700 50  0001 C CNN
F 3 "" H 3150 3700 50  0001 C CNN
	1    3150 3700
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR45
U 1 1 5A320DAE
P 3675 3750
F 0 "#PWR45" H 3675 3500 50  0001 C CNN
F 1 "GND" H 3675 3600 50  0001 C CNN
F 2 "" H 3675 3750 50  0001 C CNN
F 3 "" H 3675 3750 50  0001 C CNN
	1    3675 3750
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR46
U 1 1 5A320DF2
P 3675 4825
F 0 "#PWR46" H 3675 4575 50  0001 C CNN
F 1 "GND" H 3675 4675 50  0001 C CNN
F 2 "" H 3675 4825 50  0001 C CNN
F 3 "" H 3675 4825 50  0001 C CNN
	1    3675 4825
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR47
U 1 1 5A320E06
P 4675 5200
F 0 "#PWR47" H 4675 4950 50  0001 C CNN
F 1 "GND" H 4675 5050 50  0001 C CNN
F 2 "" H 4675 5200 50  0001 C CNN
F 3 "" H 4675 5200 50  0001 C CNN
	1    4675 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4850 5300 4850
Wire Wire Line
	5400 4700 5300 4700
Wire Wire Line
	5400 4550 5300 4550
$EndSCHEMATC
