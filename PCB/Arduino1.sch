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
Sheet 3 8
Title "T.A.R.D.I.S"
Date "2017-12-04"
Rev "3"
Comp "Altcom"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2750 2175 0    60   Input ~ 0
GND
Text HLabel 5075 4625 3    60   BiDi ~ 0
SDA
Text HLabel 5225 4625 3    60   BiDi ~ 0
SCL
Text HLabel 6150 2600 2    60   BiDi ~ 0
2
Text HLabel 6150 2750 2    60   BiDi ~ 0
3
Text HLabel 6150 2900 2    60   BiDi ~ 0
4
Text HLabel 6150 3050 2    60   BiDi ~ 0
5
Text HLabel 6150 3200 2    60   BiDi ~ 0
6
Text HLabel 6150 3350 2    60   BiDi ~ 0
7
Text HLabel 6150 3500 2    60   BiDi ~ 0
8
Text HLabel 6150 3650 2    60   BiDi ~ 0
9
Text HLabel 6150 3800 2    60   BiDi ~ 0
10
Text HLabel 6150 3950 2    60   BiDi ~ 0
11
Text HLabel 6150 4100 2    60   BiDi ~ 0
12
Text HLabel 6150 4250 2    60   BiDi ~ 0
13
$Comp
L Header1 H6
U 1 1 5A169EC3
P 5150 1875
F 0 "H6" H 5050 1975 60  0000 C CNN
F 1 "Header1" H 5150 1900 60  0001 C CNN
F 2 "" H 5150 1875 60  0001 C CNN
F 3 "" H 5150 1875 60  0001 C CNN
	1    5150 1875
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2200 4950 1975
Wire Wire Line
	5050 1975 5050 2200
Wire Wire Line
	5150 2200 5150 1975
Wire Wire Line
	5250 1975 5250 2200
Wire Wire Line
	5350 2200 5350 1975
Wire Wire Line
	5475 1975 5475 2200
NoConn ~ 4475 2600
NoConn ~ 4475 2850
NoConn ~ 4475 2925
Text HLabel 4075 3500 0    60   BiDi ~ 0
RST
$Comp
L C C13
U 1 1 5A16ADDA
P 3875 2925
F 0 "C13" H 3900 3025 50  0000 L CNN
F 1 "0.1uF" H 3900 2825 50  0000 L CNN
F 2 "" H 3913 2775 50  0001 C CNN
F 3 "" H 3875 2925 50  0001 C CNN
	1    3875 2925
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR53
U 1 1 5A16AE9D
P 4450 4250
F 0 "#PWR53" H 4450 4000 50  0001 C CNN
F 1 "GND" H 4450 4100 50  0001 C CNN
F 2 "" H 4450 4250 50  0001 C CNN
F 3 "" H 4450 4250 50  0001 C CNN
	1    4450 4250
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR54
U 1 1 5A16AEB4
P 5450 4600
F 0 "#PWR54" H 5450 4350 50  0001 C CNN
F 1 "GND" H 5450 4450 50  0001 C CNN
F 2 "" H 5450 4600 50  0001 C CNN
F 3 "" H 5450 4600 50  0001 C CNN
	1    5450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3875 2725 3875 2775
Connection ~ 3875 2750
Wire Wire Line
	3875 3075 3875 3100
Wire Wire Line
	4475 3600 4450 3600
Wire Wire Line
	4450 3600 4450 3500
Wire Wire Line
	4075 3500 4475 3500
Connection ~ 4450 3500
Wire Wire Line
	4475 3750 4450 3750
Wire Wire Line
	4450 3750 4450 4250
Wire Wire Line
	4475 4200 4450 4200
Connection ~ 4450 4200
Wire Wire Line
	4475 4050 4450 4050
Connection ~ 4450 4050
Wire Wire Line
	4475 3900 4450 3900
Connection ~ 4450 3900
Wire Wire Line
	5075 4625 5075 4550
Wire Wire Line
	5225 4550 5225 4625
Wire Wire Line
	6150 4250 6075 4250
Wire Wire Line
	6075 4100 6150 4100
Wire Wire Line
	6150 3950 6075 3950
Wire Wire Line
	6075 3800 6150 3800
Wire Wire Line
	6150 3650 6075 3650
Wire Wire Line
	6075 3500 6150 3500
Wire Wire Line
	6075 3350 6150 3350
Wire Wire Line
	6075 3200 6150 3200
Wire Wire Line
	6075 3050 6150 3050
Wire Wire Line
	6075 2900 6150 2900
Wire Wire Line
	6075 2750 6150 2750
Wire Wire Line
	6075 2600 6150 2600
$Comp
L GND-RESCUE-Tardis #PWR51
U 1 1 5A31E962
P 3875 3100
F 0 "#PWR51" H 3875 2850 50  0001 C CNN
F 1 "GND" H 3875 2950 50  0001 C CNN
F 2 "" H 3875 3100 50  0001 C CNN
F 3 "" H 3875 3100 50  0001 C CNN
	1    3875 3100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR48
U 1 1 5A31EB9F
P 2900 2050
F 0 "#PWR48" H 2900 1900 50  0001 C CNN
F 1 "+5V" H 2900 2190 50  0000 C CNN
F 2 "" H 2900 2050 50  0001 C CNN
F 3 "" H 2900 2050 50  0001 C CNN
	1    2900 2050
	1    0    0    -1  
$EndComp
Text HLabel 2750 2075 0    60   Input ~ 0
5V
Wire Wire Line
	2750 2075 2900 2075
Wire Wire Line
	2900 2075 2900 2050
$Comp
L +5V #PWR50
U 1 1 5A31EC49
P 3875 2725
F 0 "#PWR50" H 3875 2575 50  0001 C CNN
F 1 "+5V" H 3875 2865 50  0000 C CNN
F 2 "" H 3875 2725 50  0001 C CNN
F 3 "" H 3875 2725 50  0001 C CNN
	1    3875 2725
	1    0    0    -1  
$EndComp
Wire Wire Line
	4475 2750 3875 2750
$Comp
L GND-RESCUE-Tardis #PWR49
U 1 1 5A468F3C
P 2900 2200
F 0 "#PWR49" H 2900 1950 50  0001 C CNN
F 1 "GND" H 2900 2050 50  0001 C CNN
F 2 "" H 2900 2200 50  0001 C CNN
F 3 "" H 2900 2200 50  0001 C CNN
	1    2900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2175 2900 2175
Wire Wire Line
	2900 2175 2900 2200
Wire Wire Line
	5375 4550 5375 4575
Wire Wire Line
	5375 4575 5525 4575
Wire Wire Line
	5525 4575 5525 4550
Wire Wire Line
	5450 4600 5450 4575
Connection ~ 5450 4575
$Comp
L Arduino-Pro-5V U6
U 1 1 5A169E8F
P 5825 3000
F 0 "U6" H 5275 2500 60  0000 C CNN
F 1 "Arduino-Pro-5V" H 5325 2350 60  0000 C CNN
F 2 "" H 6125 2800 60  0001 C CNN
F 3 "" H 6125 2800 60  0001 C CNN
	1    5825 3000
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR52
U 1 1 5A469911
P 4450 3150
F 0 "#PWR52" H 4450 2900 50  0001 C CNN
F 1 "GND" H 4450 3000 50  0001 C CNN
F 2 "" H 4450 3150 50  0001 C CNN
F 3 "" H 4450 3150 50  0001 C CNN
	1    4450 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3150 4450 3050
Wire Wire Line
	4450 3050 4475 3050
Wire Wire Line
	4475 3125 4450 3125
Connection ~ 4450 3125
$EndSCHEMATC
