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
Sheet 4 8
Title "T.A.R.D.I.S"
Date "2017-12-04"
Rev "3"
Comp "Altcom"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino-Pro-5V U7
U 1 1 5A1A817D
P 4575 2600
F 0 "U7" H 4025 2100 60  0000 C CNN
F 1 "Arduino-Pro-5V" H 4075 1950 60  0000 C CNN
F 2 "Footprints:ArduinoMINIPRO" H 4875 2400 60  0001 C CNN
F 3 "" H 4875 2400 60  0001 C CNN
	1    4575 2600
	1    0    0    -1  
$EndComp
Text HLabel 3150 3100 0    60   Input ~ 0
RST
Text HLabel 3975 4250 3    60   BiDi ~ 0
SCL
Text HLabel 3825 4250 3    60   BiDi ~ 0
SDA
Text HLabel 4925 2200 2    60   BiDi ~ 0
2
Text HLabel 4925 2350 2    60   BiDi ~ 0
3
Text HLabel 4925 2500 2    60   BiDi ~ 0
4
Text HLabel 4925 2650 2    60   BiDi ~ 0
5
Text HLabel 4925 2800 2    60   BiDi ~ 0
6
Text HLabel 4925 2950 2    60   BiDi ~ 0
7
Text HLabel 4925 3100 2    60   BiDi ~ 0
8
Text HLabel 4925 3250 2    60   BiDi ~ 0
9
Text HLabel 4925 3400 2    60   BiDi ~ 0
10
Text HLabel 4925 3550 2    60   BiDi ~ 0
11
Text HLabel 4925 3700 2    60   BiDi ~ 0
12
Text HLabel 4925 3850 2    60   BiDi ~ 0
13
NoConn ~ 3225 2200
$Comp
L C C14
U 1 1 5A1AE13E
P 2625 2575
F 0 "C14" H 2475 2675 50  0000 L CNN
F 1 "0.1uF" H 2400 2475 50  0000 L CNN
F 2 "" H 2663 2425 50  0001 C CNN
F 3 "" H 2625 2575 50  0001 C CNN
	1    2625 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	2625 2750 2625 2725
Wire Wire Line
	4825 2200 4925 2200
Wire Wire Line
	4825 2350 4925 2350
Wire Wire Line
	4825 2500 4925 2500
Wire Wire Line
	4825 2650 4925 2650
Wire Wire Line
	4825 2800 4925 2800
Wire Wire Line
	4925 2950 4825 2950
Wire Wire Line
	4825 3100 4925 3100
Wire Wire Line
	4825 3250 4925 3250
Wire Wire Line
	4925 3400 4825 3400
Wire Wire Line
	4825 3550 4925 3550
Wire Wire Line
	4925 3700 4825 3700
Wire Wire Line
	4825 3850 4925 3850
Wire Wire Line
	3825 4150 3825 4250
Wire Wire Line
	3975 4150 3975 4250
Wire Wire Line
	2625 2325 2625 2425
Connection ~ 2625 2350
Wire Wire Line
	3150 3100 3225 3100
$Comp
L Header1 H7
U 1 1 5A166848
P 3900 1425
F 0 "H7" H 3800 1525 60  0000 C CNN
F 1 "Header1" H 3900 1450 60  0001 C CNN
F 2 "Footprints:Pin_Header_Straight_1x06_Pitch2.54mm" H 3900 1425 60  0001 C CNN
F 3 "" H 3900 1425 60  0001 C CNN
	1    3900 1425
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1800 3900 1525
Wire Wire Line
	4000 1800 4000 1525
Wire Wire Line
	4100 1800 4100 1525
Wire Wire Line
	4225 1800 4225 1525
Wire Wire Line
	3225 3200 3200 3200
Wire Wire Line
	3200 3200 3200 3100
Connection ~ 3200 3100
Wire Wire Line
	3225 3350 3200 3350
Wire Wire Line
	3200 3350 3200 3825
Wire Wire Line
	3200 3800 3225 3800
Wire Wire Line
	3225 3650 3200 3650
Connection ~ 3200 3650
Wire Wire Line
	3225 3500 3200 3500
Connection ~ 3200 3500
Wire Wire Line
	4125 4150 4125 4175
Wire Wire Line
	4125 4175 4275 4175
Wire Wire Line
	4275 4175 4275 4150
$Comp
L GND-RESCUE-Tardis #PWR60
U 1 1 5A167E2B
P 3200 3825
F 0 "#PWR60" H 3200 3575 50  0001 C CNN
F 1 "GND" H 3200 3675 50  0001 C CNN
F 2 "" H 3200 3825 50  0001 C CNN
F 3 "" H 3200 3825 50  0001 C CNN
	1    3200 3825
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR61
U 1 1 5A167E3F
P 4200 4200
F 0 "#PWR61" H 4200 3950 50  0001 C CNN
F 1 "GND" H 4200 4050 50  0001 C CNN
F 2 "" H 4200 4200 50  0001 C CNN
F 3 "" H 4200 4200 50  0001 C CNN
	1    4200 4200
	1    0    0    -1  
$EndComp
Connection ~ 3200 3800
Wire Wire Line
	4200 4200 4200 4175
Connection ~ 4200 4175
Wire Wire Line
	3800 1800 3800 1525
Wire Wire Line
	3700 1525 3700 1800
NoConn ~ 3225 2450
NoConn ~ 3225 2525
Wire Wire Line
	3225 2725 3200 2725
Wire Wire Line
	3200 2650 3200 2750
Text HLabel 1400 2225 0    60   Input ~ 0
GND
$Comp
L GND-RESCUE-Tardis #PWR56
U 1 1 5A31F3E8
P 1550 2250
F 0 "#PWR56" H 1550 2000 50  0001 C CNN
F 1 "GND" H 1550 2100 50  0001 C CNN
F 2 "" H 1550 2250 50  0001 C CNN
F 3 "" H 1550 2250 50  0001 C CNN
	1    1550 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2225 1550 2225
Wire Wire Line
	1550 2225 1550 2250
$Comp
L +5V #PWR55
U 1 1 5A31F3F0
P 1550 2100
F 0 "#PWR55" H 1550 1950 50  0001 C CNN
F 1 "+5V" H 1550 2240 50  0000 C CNN
F 2 "" H 1550 2100 50  0001 C CNN
F 3 "" H 1550 2100 50  0001 C CNN
	1    1550 2100
	1    0    0    -1  
$EndComp
Text HLabel 1400 2125 0    60   Input ~ 0
5V
Wire Wire Line
	1400 2125 1550 2125
Wire Wire Line
	1550 2125 1550 2100
$Comp
L +5V #PWR57
U 1 1 5A31F40B
P 2625 2325
F 0 "#PWR57" H 2625 2175 50  0001 C CNN
F 1 "+5V" H 2625 2465 50  0000 C CNN
F 2 "" H 2625 2325 50  0001 C CNN
F 3 "" H 2625 2325 50  0001 C CNN
	1    2625 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	2625 2350 3225 2350
$Comp
L GND-RESCUE-Tardis #PWR58
U 1 1 5A31F497
P 2625 2750
F 0 "#PWR58" H 2625 2500 50  0001 C CNN
F 1 "GND" H 2625 2600 50  0001 C CNN
F 2 "" H 2625 2750 50  0001 C CNN
F 3 "" H 2625 2750 50  0001 C CNN
	1    2625 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2650 3225 2650
$Comp
L GND-RESCUE-Tardis #PWR59
U 1 1 5A468998
P 3200 2750
F 0 "#PWR59" H 3200 2500 50  0001 C CNN
F 1 "GND" H 3200 2600 50  0001 C CNN
F 2 "" H 3200 2750 50  0001 C CNN
F 3 "" H 3200 2750 50  0001 C CNN
	1    3200 2750
	1    0    0    -1  
$EndComp
Connection ~ 3200 2725
$EndSCHEMATC
