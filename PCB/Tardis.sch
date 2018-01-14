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
Sheet 1 8
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
L ED800 H1
U 1 1 59E919E0
P 875 2175
F 0 "H1" H 775 2425 60  0000 C CNN
F 1 "ED800/2" H 875 1925 60  0000 C CNN
F 2 "Footprints:ED800" H 475 2625 60  0001 C CNN
F 3 "" H 475 2625 60  0001 C CNN
F 4 "ED1633-ND" H 875 2175 60  0001 C CNN "Vendor"
	1    875  2175
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59E931BA
P 1875 2325
F 0 "C1" H 1900 2425 50  0000 L CNN
F 1 "0.1uF" H 1900 2225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1913 2175 50  0001 C CNN
F 3 "" H 1875 2325 50  0001 C CNN
	1    1875 2325
	1    0    0    -1  
$EndComp
$Comp
L L4940 U1
U 1 1 59EA6D8B
P 2400 2075
F 0 "U1" H 2150 2375 60  0000 C CNN
F 1 "L4940" H 2250 2275 60  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220-3_Horizontal" H 2450 2075 60  0001 C CNN
F 3 "" H 2450 2075 60  0001 C CNN
	1    2400 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	2925 2525 2925 2475
Wire Wire Line
	1225 2525 2925 2525
Connection ~ 2400 2525
Wire Wire Line
	2400 2575 2400 2525
$Comp
L CP C2
U 1 1 59EA7E3A
P 2925 2325
F 0 "C2" H 2950 2425 50  0000 L CNN
F 1 "22uF" H 2950 2225 50  0000 L CNN
F 2 "Footprints:RADIAL_5MM" H 2963 2175 50  0001 C CNN
F 3 "" H 2925 2325 50  0001 C CNN
	1    2925 2325
	1    0    0    -1  
$EndComp
$Comp
L MT8888C U2
U 1 1 59EFB2EC
P 8500 650
F 0 "U2" H 8500 700 60  0000 C CNN
F 1 "MT8888C" H 8650 600 60  0000 C CNN
F 2 "Footprints:SOIC-20" H 8500 650 60  0001 C CNN
F 3 "" H 8500 650 60  0001 C CNN
	1    8500 650 
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 59EFB491
P 7000 1000
F 0 "C3" V 6850 950 50  0000 L CNN
F 1 "100nF" V 7150 900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7038 850 50  0001 C CNN
F 3 "" H 7000 1000 50  0001 C CNN
F 4 "5%" V 6950 1100 39  0000 C CNN "%"
	1    7000 1000
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 59EFB683
P 7450 1000
F 0 "R19" V 7350 1000 50  0000 C CNN
F 1 "100k" V 7450 1000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7380 1000 50  0001 C CNN
F 3 "" H 7450 1000 50  0001 C CNN
F 4 "1%" V 7550 1000 39  0000 C CNN "%"
	1    7450 1000
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 59EFB918
P 7900 1150
F 0 "R23" V 7800 1100 50  0000 C CNN
F 1 "100k" V 7900 1150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7830 1150 50  0001 C CNN
F 3 "" H 7900 1150 50  0001 C CNN
F 4 "1%" V 8000 1150 39  0000 C CNN "%"
	1    7900 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 1000 7300 1000
Wire Wire Line
	6650 1000 6850 1000
Wire Wire Line
	8050 1150 8250 1150
Wire Wire Line
	7600 1000 8250 1000
Wire Wire Line
	7750 1150 7650 1150
Wire Wire Line
	7650 1150 7650 1000
Connection ~ 7650 1000
Wire Wire Line
	8250 850  8200 850 
Wire Wire Line
	8200 850  8200 1300
Wire Wire Line
	8200 1300 8250 1300
$Comp
L R R17
U 1 1 59EFD02D
P 7250 1600
F 0 "R17" V 7150 1600 50  0000 C CNN
F 1 "4.7M" V 7250 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 1600 50  0001 C CNN
F 3 "" H 7250 1600 50  0001 C CNN
F 4 "10%" V 7350 1600 39  0000 C CNN "%"
	1    7250 1600
	0    1    1    0   
$EndComp
$Comp
L Crystal Y1
U 1 1 59EFD08C
P 7700 1750
F 0 "Y1" H 7550 1800 50  0000 C CNN
F 1 "3.579545MHz" H 8000 1800 39  0000 C CNN
F 2 "Crystals:Crystal_SMD_HC49-SD_HandSoldering" H 7700 1750 50  0001 C CNN
F 3 "" H 7700 1750 50  0001 C CNN
	1    7700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1750 8250 1750
Wire Wire Line
	6800 1450 8250 1450
Wire Wire Line
	7100 1600 7050 1600
Wire Wire Line
	7050 1600 7050 1450
Connection ~ 7050 1450
Wire Wire Line
	7400 1600 8250 1600
Wire Wire Line
	7450 1600 7450 1750
Wire Wire Line
	7450 1750 7550 1750
Connection ~ 7450 1600
$Comp
L C C5
U 1 1 59EFD8A6
P 7200 2075
F 0 "C5" H 7100 2000 50  0000 L CNN
F 1 "10nF" H 7000 2175 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7238 1925 50  0001 C CNN
F 3 "" H 7200 2075 50  0001 C CNN
F 4 "5%" H 7350 2075 39  0000 C CNN "%"
	1    7200 2075
	-1   0    0    1   
$EndComp
$Comp
L R R21
U 1 1 59EFDC7B
P 7700 2075
F 0 "R21" H 7575 2075 50  0000 C CNN
F 1 "10k" V 7700 2075 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7630 2075 50  0001 C CNN
F 3 "" H 7700 2075 50  0001 C CNN
F 4 "1%" H 7800 2075 39  0000 C CNN "%"
	1    7700 2075
	-1   0    0    1   
$EndComp
Wire Wire Line
	6800 1900 8250 1900
Connection ~ 7700 1900
Connection ~ 7200 1900
Wire Wire Line
	7700 2275 7700 2225
Wire Wire Line
	7200 2275 7700 2275
Wire Wire Line
	7200 2275 7200 2225
Text GLabel 8250 2050 0    60   BiDi ~ 0
uC_1
Text GLabel 8250 2200 0    60   BiDi ~ 0
uC_2
$Comp
L R R27
U 1 1 59F8D848
P 10350 1250
F 0 "R27" H 10250 1250 50  0000 C CNN
F 1 "3.3k" V 10350 1250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10280 1250 50  0001 C CNN
F 3 "" H 10350 1250 50  0001 C CNN
F 4 "10%" H 10450 1250 39  0000 C CNN "%"
	1    10350 1250
	-1   0    0    1   
$EndComp
$Comp
L R R25
U 1 1 59F8D929
P 9550 1150
F 0 "R25" V 9650 1150 50  0000 C CNN
F 1 "374k" V 9550 1150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9480 1150 50  0001 C CNN
F 3 "" H 9550 1150 50  0001 C CNN
F 4 "1%" V 9450 1150 39  0000 C CNN "%"
	1    9550 1150
	0    -1   -1   0   
$EndComp
$Comp
L C C7
U 1 1 59F8D975
P 9950 1000
F 0 "C7" V 10000 1050 50  0000 L CNN
F 1 "100nF" V 9800 850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9988 850 50  0001 C CNN
F 3 "" H 9950 1000 50  0001 C CNN
F 4 "5%" V 10000 900 39  0000 C CNN "%"
	1    9950 1000
	0    -1   -1   0   
$EndComp
$Comp
L C C9
U 1 1 59F8E7DB
P 10650 850
F 0 "C9" V 10700 900 50  0000 L CNN
F 1 "100nF" V 10500 700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10688 700 50  0001 C CNN
F 3 "" H 10650 850 50  0001 C CNN
F 4 "10%" V 10700 750 39  0000 C CNN "%"
	1    10650 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 1000 9800 1000
Wire Wire Line
	9700 1150 9700 1000
Connection ~ 9700 1000
Wire Wire Line
	9400 1150 9350 1150
Wire Wire Line
	10150 1000 10100 1000
Wire Wire Line
	10150 750  10150 1000
Wire Wire Line
	9350 850  10500 850 
Connection ~ 10150 850 
Connection ~ 10350 850 
Wire Wire Line
	10350 1400 10350 1900
Wire Wire Line
	9350 1900 10425 1900
Wire Wire Line
	10350 1100 10350 850 
Wire Wire Line
	10950 850  10800 850 
Text GLabel 9700 1300 2    60   BiDi ~ 0
uC_3
Text GLabel 9700 1450 2    60   BiDi ~ 0
uC_4
Text GLabel 9700 1600 2    60   BiDi ~ 0
uC_5
Text GLabel 9700 1750 2    60   BiDi ~ 0
uC_6
Text GLabel 9700 2050 2    60   BiDi ~ 0
uC_7
Text GLabel 9700 2200 2    60   BiDi ~ 0
uC_8
Wire Wire Line
	9700 1300 9350 1300
Wire Wire Line
	9350 1450 9700 1450
Wire Wire Line
	9700 1600 9350 1600
Wire Wire Line
	9350 1750 9700 1750
Wire Wire Line
	9700 2050 9350 2050
Wire Wire Line
	9350 2200 9700 2200
$Comp
L MT8888C U3
U 1 1 59F90EEF
P 8500 2450
F 0 "U3" H 8500 2500 60  0000 C CNN
F 1 "MT8888C" H 8650 2400 60  0000 C CNN
F 2 "Footprints:SOIC-20" H 8500 2450 60  0001 C CNN
F 3 "" H 8500 2450 60  0001 C CNN
	1    8500 2450
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 59F91074
P 7950 2950
F 0 "R24" V 7850 2900 50  0000 C CNN
F 1 "100k" V 7950 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7880 2950 50  0001 C CNN
F 3 "" H 7950 2950 50  0001 C CNN
F 4 "1%" V 8050 2950 39  0000 C CNN "%"
	1    7950 2950
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 59F910E6
P 7500 2800
F 0 "R20" V 7400 2800 50  0000 C CNN
F 1 "100k" V 7500 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7430 2800 50  0001 C CNN
F 3 "" H 7500 2800 50  0001 C CNN
F 4 "1%" V 7600 2800 39  0000 C CNN "%"
	1    7500 2800
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 59F91159
P 7000 2800
F 0 "C4" V 6850 2750 50  0000 L CNN
F 1 "100nF" V 7150 2700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7038 2650 50  0001 C CNN
F 3 "" H 7000 2800 50  0001 C CNN
F 4 "5%" V 6950 2900 39  0000 C CNN "%"
	1    7000 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 2800 8250 2800
Wire Wire Line
	7800 2950 7700 2950
Wire Wire Line
	7700 2950 7700 2800
Connection ~ 7700 2800
Wire Wire Line
	8100 2950 8250 2950
Wire Wire Line
	7350 2800 7150 2800
Wire Wire Line
	6850 2800 6750 2800
Wire Wire Line
	8250 2650 8200 2650
Wire Wire Line
	8200 2650 8200 3100
Wire Wire Line
	8200 3100 8250 3100
$Comp
L R R18
U 1 1 59F916A4
P 7250 3400
F 0 "R18" V 7150 3400 50  0000 C CNN
F 1 "4.7M" V 7250 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 3400 50  0001 C CNN
F 3 "" H 7250 3400 50  0001 C CNN
F 4 "10%" V 7350 3400 39  0000 C CNN "%"
	1    7250 3400
	0    1    1    0   
$EndComp
$Comp
L Crystal Y2
U 1 1 59F9179A
P 7700 3550
F 0 "Y2" H 7550 3600 50  0000 C CNN
F 1 "3.579545MHz" H 8000 3600 39  0000 C CNN
F 2 "Crystals:Crystal_SMD_HC49-SD_HandSoldering" H 7700 3550 50  0001 C CNN
F 3 "" H 7700 3550 50  0001 C CNN
	1    7700 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3250 8250 3250
Wire Wire Line
	7100 3400 7050 3400
Wire Wire Line
	7050 3400 7050 3250
Connection ~ 7050 3250
Wire Wire Line
	7400 3400 8250 3400
Wire Wire Line
	7550 3550 7450 3550
Wire Wire Line
	7450 3550 7450 3400
Connection ~ 7450 3400
Wire Wire Line
	7850 3550 8250 3550
$Comp
L R R22
U 1 1 59F91B4D
P 7700 3875
F 0 "R22" H 7575 3875 50  0000 C CNN
F 1 "10k" V 7700 3875 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7630 3875 50  0001 C CNN
F 3 "" H 7700 3875 50  0001 C CNN
F 4 "1%" H 7800 3875 39  0000 C CNN "%"
	1    7700 3875
	-1   0    0    1   
$EndComp
$Comp
L C C6
U 1 1 59F91BBD
P 7250 3875
F 0 "C6" H 7150 3800 50  0000 L CNN
F 1 "10nF" H 7050 3975 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7288 3725 50  0001 C CNN
F 3 "" H 7250 3875 50  0001 C CNN
F 4 "5%" H 7400 3875 39  0000 C CNN "%"
	1    7250 3875
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 3700 8250 3700
Wire Wire Line
	7250 4050 7700 4050
Connection ~ 7500 4050
Connection ~ 7450 2275
Connection ~ 7250 3700
Text GLabel 8250 3850 0    60   Input ~ 0
uC_9
Text GLabel 8250 4000 0    60   Input ~ 0
uC_10
$Comp
L R R26
U 1 1 59F9220B
P 9550 2950
F 0 "R26" V 9650 2950 50  0000 C CNN
F 1 "374k" V 9550 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9480 2950 50  0001 C CNN
F 3 "" H 9550 2950 50  0001 C CNN
F 4 "1%" V 9450 2950 39  0000 C CNN "%"
	1    9550 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 2950 9400 2950
Wire Wire Line
	9700 2950 9700 2800
Wire Wire Line
	9350 2800 9800 2800
$Comp
L C C8
U 1 1 59F924DA
P 9950 2800
F 0 "C8" V 10000 2850 50  0000 L CNN
F 1 "100nF" V 9800 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9988 2650 50  0001 C CNN
F 3 "" H 9950 2800 50  0001 C CNN
F 4 "5%" V 10000 2700 39  0000 C CNN "%"
	1    9950 2800
	0    -1   -1   0   
$EndComp
Connection ~ 9700 2800
Wire Wire Line
	9350 2650 10500 2650
Wire Wire Line
	10150 2550 10150 2800
Wire Wire Line
	10150 2800 10100 2800
$Comp
L R R28
U 1 1 59F926F2
P 10350 3050
F 0 "R28" H 10200 3050 50  0000 C CNN
F 1 "3.3k" V 10350 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10280 3050 50  0001 C CNN
F 3 "" H 10350 3050 50  0001 C CNN
F 4 "10%" H 10450 3050 39  0000 C CNN "%"
	1    10350 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	10350 2650 10350 2900
Connection ~ 10150 2650
$Comp
L C C10
U 1 1 59F92900
P 10650 2650
F 0 "C10" V 10700 2700 50  0000 L CNN
F 1 "100nF" V 10500 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10688 2500 50  0001 C CNN
F 3 "" H 10650 2650 50  0001 C CNN
F 4 "10%" V 10700 2550 39  0000 C CNN "%"
	1    10650 2650
	0    -1   -1   0   
$EndComp
Connection ~ 10350 2650
Wire Wire Line
	10800 2650 10925 2650
Wire Wire Line
	9350 3700 10425 3700
Wire Wire Line
	10350 3700 10350 3200
Text GLabel 9700 3100 2    60   Input ~ 0
uC_11
Text GLabel 9700 3250 2    60   Input ~ 0
uC_12
Text GLabel 9700 3400 2    60   Input ~ 0
uC_13
Text GLabel 9700 3550 2    60   Input ~ 0
uC_14
Text GLabel 9700 3850 2    60   Input ~ 0
uC_15
Text GLabel 9700 4000 2    60   Input ~ 0
uC_16
Wire Wire Line
	9350 3100 9700 3100
Wire Wire Line
	9700 3250 9350 3250
Wire Wire Line
	9350 3400 9700 3400
Wire Wire Line
	9700 3550 9350 3550
Wire Wire Line
	9350 3850 9700 3850
Wire Wire Line
	9700 4000 9350 4000
$Sheet
S 950  6175 550  1250
U 5A11F431
F0 "Arduino2" 30
F1 "Arduino2.sch" 30
F2 "RST" B L 950 6825 60 
F3 "SCL" B L 950 7225 60 
F4 "SDA" B L 950 7325 60 
F5 "2" B R 1500 6225 60 
F6 "3" B R 1500 6325 60 
F7 "4" B R 1500 6425 60 
F8 "5" B R 1500 6525 60 
F9 "6" B R 1500 6625 60 
F10 "7" B R 1500 6725 60 
F11 "8" B R 1500 6825 60 
F12 "9" B R 1500 6925 60 
F13 "10" B R 1500 7025 60 
F14 "5V" I L 950 6225 60 
F15 "GND" I L 950 6325 60 
F16 "11" B R 1500 7125 60 
F17 "12" B R 1500 7225 60 
F18 "13" B R 1500 7325 60 
$EndSheet
$Sheet
S 950  4400 550  1250
U 5A121926
F0 "Arduino1" 30
F1 "Arduino1.sch" 30
F2 "SDA" B L 950 5550 60 
F3 "SCL" B L 950 5450 60 
F4 "RST" I L 950 5050 60 
F5 "2" B R 1500 4450 60 
F6 "3" B R 1500 4550 60 
F7 "4" B R 1500 4650 60 
F8 "5" B R 1500 4750 60 
F9 "6" B R 1500 4850 60 
F10 "7" B R 1500 4950 60 
F11 "8" B R 1500 5050 60 
F12 "9" B R 1500 5150 60 
F13 "10" B R 1500 5250 60 
F14 "11" I R 1500 5350 60 
F15 "12" I R 1500 5450 60 
F16 "13" I R 1500 5550 60 
F17 "5V" I L 950 4450 60 
F18 "GND" I L 950 4550 60 
$EndSheet
$Sheet
S 950  2900 550  1250
U 5A12503B
F0 "Master" 30
F1 "Arduino3.sch" 30
F2 "SCL" B L 950 3950 60 
F3 "SDA" B L 950 4050 60 
F4 "2" B R 1500 2950 60 
F5 "3" B R 1500 3050 60 
F6 "4" B R 1500 3150 60 
F7 "5" B R 1500 3250 60 
F8 "6" B R 1500 3350 60 
F9 "7" B R 1500 3450 60 
F10 "8" B R 1500 3550 60 
F11 "9" B R 1500 3650 60 
F12 "10" B R 1500 3750 60 
F13 "11" B R 1500 3850 60 
F14 "12" B R 1500 3950 60 
F15 "13" B R 1500 4050 60 
F16 "5V" I L 950 2950 60 
F17 "GND" I L 950 3050 60 
F18 "RST" I L 950 3550 60 
$EndSheet
Text GLabel 850  5450 0    60   BiDi ~ 0
SCL
Text GLabel 850  5550 0    60   BiDi ~ 0
SDA
Text GLabel 850  3950 0    60   BiDi ~ 0
SCL
Text GLabel 850  4050 0    60   BiDi ~ 0
SDA
Text GLabel 850  7225 0    60   BiDi ~ 0
SCL
Text GLabel 850  7325 0    60   BiDi ~ 0
SDA
Wire Wire Line
	850  7225 950  7225
Wire Wire Line
	950  7325 850  7325
Wire Wire Line
	850  5450 950  5450
Wire Wire Line
	850  5550 950  5550
Wire Wire Line
	850  3950 950  3950
Wire Wire Line
	950  4050 850  4050
Text GLabel 850  3550 0    60   Input ~ 0
RST
Text GLabel 850  5050 0    60   Input ~ 0
RST
Text GLabel 850  6825 0    60   Input ~ 0
RST
Wire Wire Line
	950  6825 850  6825
Wire Wire Line
	950  5050 850  5050
Wire Wire Line
	950  3550 850  3550
Wire Wire Line
	1225 2275 1225 2525
Connection ~ 1875 2525
Wire Wire Line
	2925 2050 2925 2175
Connection ~ 2925 2075
Wire Wire Line
	1875 2475 1875 2525
Text GLabel 1700 4750 2    60   BiDi ~ 0
uC_3
Text GLabel 1700 4850 2    60   BiDi ~ 0
uC_4
Text GLabel 1700 4950 2    60   BiDi ~ 0
uC_5
Text GLabel 1700 5050 2    60   BiDi ~ 0
uC_6
Text GLabel 1700 5150 2    60   BiDi ~ 0
uC_7
Text GLabel 1700 5250 2    60   BiDi ~ 0
uC_8
Text GLabel 1700 4550 2    60   BiDi ~ 0
uC_1
Text GLabel 1700 4650 2    60   BiDi ~ 0
uC_2
Text GLabel 1700 4450 2    60   BiDi ~ 0
~irq1
Text GLabel 10425 1900 2    60   BiDi ~ 0
~irq1
Text GLabel 10425 3700 2    60   BiDi ~ 0
~irq2
Text GLabel 1700 6225 2    60   BiDi ~ 0
~irq2
Connection ~ 10350 1900
Connection ~ 10350 3700
Text GLabel 1700 6525 2    60   Input ~ 0
uC_11
Text GLabel 1700 6625 2    60   Input ~ 0
uC_12
Text GLabel 1700 6725 2    60   Input ~ 0
uC_13
Text GLabel 1700 6825 2    60   Input ~ 0
uC_14
Text GLabel 1700 6925 2    60   Input ~ 0
uC_15
Text GLabel 1700 7025 2    60   Input ~ 0
uC_16
Text GLabel 1700 6325 2    60   Input ~ 0
uC_9
Text GLabel 1700 6425 2    60   Input ~ 0
uC_10
Wire Wire Line
	1500 4450 1700 4450
Wire Wire Line
	1700 4550 1500 4550
Wire Wire Line
	1500 4650 1700 4650
Wire Wire Line
	1500 4750 1700 4750
Wire Wire Line
	1500 4850 1700 4850
Wire Wire Line
	1700 4950 1500 4950
Wire Wire Line
	1500 5050 1700 5050
Wire Wire Line
	1700 5150 1500 5150
Wire Wire Line
	1700 5250 1500 5250
Wire Wire Line
	1700 6225 1500 6225
Wire Wire Line
	1500 6325 1700 6325
Wire Wire Line
	1700 6425 1500 6425
Wire Wire Line
	1500 6525 1700 6525
Wire Wire Line
	1700 6625 1500 6625
Wire Wire Line
	1500 6725 1700 6725
Wire Wire Line
	1700 6825 1500 6825
Wire Wire Line
	1500 6925 1700 6925
Wire Wire Line
	1700 7025 1500 7025
$Comp
L FONA_Header H3
U 1 1 5A1BE776
P 5075 625
F 0 "H3" H 5125 625 60  0000 C CNN
F 1 "FONA_Header" H 5350 -600 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x18_Pitch2.54mm" H 5075 625 60  0001 C CNN
F 3 "" H 5075 625 60  0001 C CNN
	1    5075 625 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 825  4875 825 
Wire Wire Line
	4850 725  4850 825 
Connection ~ 4850 750 
Text GLabel 4800 1150 0    60   BiDi ~ 0
Fona_Rx
Text GLabel 4800 1250 0    60   BiDi ~ 0
Fona_Tx
Text GLabel 4800 1350 0    60   BiDi ~ 0
Fona_RST
Wire Wire Line
	5675 750  5700 750 
Wire Wire Line
	5700 750  5700 850 
Wire Wire Line
	5700 825  5675 825 
Connection ~ 5700 825 
Wire Wire Line
	4800 1150 4875 1150
Wire Wire Line
	4875 1250 4800 1250
Wire Wire Line
	4800 1350 4875 1350
Text GLabel 1725 3150 2    60   BiDi ~ 0
Fona_Rx
Text GLabel 1725 3050 2    60   BiDi ~ 0
Fona_Tx
Text GLabel 1725 2950 2    60   BiDi ~ 0
Fona_RST
Wire Wire Line
	1500 2950 1725 2950
Wire Wire Line
	1725 3050 1500 3050
Wire Wire Line
	1725 3150 1500 3150
Text GLabel 1725 3250 2    60   Input ~ 0
BTN1
Text GLabel 1725 3350 2    60   Input ~ 0
BTN2
Text GLabel 1725 3450 2    60   Input ~ 0
BTN3
Text GLabel 1725 3550 2    60   Input ~ 0
BTN4
Wire Wire Line
	1725 3250 1500 3250
Wire Wire Line
	1500 3350 1725 3350
Wire Wire Line
	1725 3450 1500 3450
Wire Wire Line
	1500 3550 1725 3550
Text GLabel 1750 3650 2    60   Output ~ 0
LED1
Text GLabel 1750 3750 2    60   Output ~ 0
LED2
Text GLabel 1750 3850 2    60   Output ~ 0
LED3
Text GLabel 1750 3950 2    60   Output ~ 0
LED4
Text GLabel 1750 4050 2    60   Output ~ 0
LED5
$Sheet
S 10275 5150 550  925 
U 5A1C89E5
F0 "LedArray" 30
F1 "LedArray.sch" 30
F2 "LED5" I L 10275 6025 60 
F3 "LED4" I L 10275 5900 60 
F4 "LED3" I L 10275 5775 60 
F5 "LED2" I L 10275 5650 60 
F6 "LED1" I L 10275 5525 60 
F7 "5V" I L 10275 5200 60 
F8 "GND" I L 10275 5300 60 
$EndSheet
Text GLabel 10150 5525 0    60   Input ~ 0
LED1
Text GLabel 10150 5650 0    60   Input ~ 0
LED2
Text GLabel 10150 5775 0    60   Input ~ 0
LED3
Text GLabel 10150 5900 0    60   Input ~ 0
LED4
Text GLabel 10150 6025 0    60   Input ~ 0
LED5
Wire Wire Line
	1500 3650 1750 3650
Wire Wire Line
	1500 3750 1750 3750
Wire Wire Line
	1750 3850 1500 3850
Wire Wire Line
	1500 3950 1750 3950
Wire Wire Line
	1750 4050 1500 4050
Wire Wire Line
	10150 5525 10275 5525
Wire Wire Line
	10150 5650 10275 5650
Wire Wire Line
	10150 5775 10275 5775
Wire Wire Line
	10275 5900 10150 5900
Wire Wire Line
	10150 6025 10275 6025
Text Notes 10275 6325 0    60   ~ 12
LEDS
Wire Notes Line
	9550 4850 9550 6450
Wire Notes Line
	5700 6450 11150 6450
Wire Notes Line
	11150 6450 11150 4750
Wire Notes Line
	11150 4750 5700 4750
Wire Notes Line
	9550 4750 9550 4875
$Sheet
S 8600 5075 850  950 
U 5A1EEEAC
F0 "Buttons" 30
F1 "Buttons.sch" 30
F2 "5V" I L 8600 5125 60 
F3 "GND" I L 8600 5225 60 
F4 "RST" O L 8600 5475 60 
F5 "BTN1" O L 8600 5600 60 
F6 "BTN2" O L 8600 5725 60 
F7 "BTN3" O L 8600 5850 60 
F8 "BTN4" O L 8600 5975 60 
$EndSheet
Text GLabel 8475 5475 0    60   Output ~ 0
RST
Text GLabel 8475 5600 0    60   Output ~ 0
BTN1
Text GLabel 8475 5725 0    60   Output ~ 0
BTN2
Text GLabel 8475 5850 0    60   Output ~ 0
BTN3
Text GLabel 8475 5975 0    60   Output ~ 0
BTN4
Wire Wire Line
	8475 5975 8600 5975
Wire Wire Line
	8600 5850 8475 5850
Wire Wire Line
	8475 5725 8600 5725
Wire Wire Line
	8600 5600 8475 5600
Wire Wire Line
	8475 5475 8600 5475
Wire Notes Line
	7875 4750 7875 6450
Text Notes 8425 6325 0    60   ~ 12
BUTTONS
$Comp
L 1935187 H2
U 1 1 5A245C21
P 4600 4400
F 0 "H2" H 4650 4625 60  0000 C CNN
F 1 "1935187" H 4800 3850 60  0000 C CNN
F 2 "Footprints:1935187" H 4600 4400 60  0001 C CNN
F 3 "" H 4600 4400 60  0001 C CNN
F 4 "277-1579-ND" H 4600 4400 60  0001 C CNN "Vendor"
	1    4600 4400
	1    0    0    -1  
$EndComp
$Sheet
S 6650 5300 775  525 
U 5A2B81A8
F0 "PTT" 30
F1 "PTT.sch" 30
F2 "SPKR_OUT2_RAW_P" I L 6650 5675 60 
F3 "GND" I L 6650 5450 60 
F4 "5V" I L 6650 5350 60 
F5 "uC_PTT" O R 7425 5350 60 
$EndSheet
$Sheet
S 3300 5875 1575 1025
U 5A2392E1
F0 "Tone Filtering" 30
F1 "tonefiltering.sch" 30
F2 "MIC_IN_P" O R 4875 5950 60 
F3 "MIC_IN_N" O R 4875 6050 60 
F4 "SPKR_OUT_P" O R 4875 6250 60 
F5 "SPKR_OUT_N" O R 4875 6350 60 
F6 "GND" I L 3300 6050 60 
F7 "5V" I L 3300 5950 60 
F8 "~STBY" I R 4875 6825 60 
$EndSheet
Wire Wire Line
	5000 5950 4875 5950
Wire Wire Line
	4875 6050 5000 6050
Text GLabel 4800 1650 0    60   Input ~ 0
SPKR_OUT1_P_RAW
Text GLabel 4275 4450 0    60   Input ~ 0
MIC_IN1_P_RAW
Text GLabel 5000 5950 2    60   Input ~ 0
MIC_IN1_P
Text GLabel 5000 6050 2    60   Input ~ 0
MIC_IN1_N
Text GLabel 4800 1450 0    60   Input ~ 0
MIC_IN2_P
Text GLabel 4800 1550 0    60   Input ~ 0
MIC_IN2_N
Wire Wire Line
	4800 1450 4875 1450
Wire Wire Line
	4875 1550 4800 1550
Text GLabel 4800 1750 0    60   Input ~ 0
SPKR_OUT1_N_RAW
Wire Wire Line
	4800 1650 4875 1650
Wire Wire Line
	4875 1750 4800 1750
Text GLabel 5000 6250 2    60   Input ~ 0
SPKR_OUT1_P
Text GLabel 5000 6350 2    60   Input ~ 0
SPKR_OUT1_N
Wire Wire Line
	5000 6250 4875 6250
Wire Wire Line
	4875 6350 5000 6350
Text GLabel 4275 4300 0    60   Input ~ 0
SPKR_OUT2_P_RAW
Wire Wire Line
	4850 750  4875 750 
$Comp
L +5V #PWR01
U 1 1 5A2B0D81
P 4850 725
F 0 "#PWR01" H 4850 575 50  0001 C CNN
F 1 "+5V" H 4850 865 50  0000 C CNN
F 2 "" H 4850 725 50  0001 C CNN
F 3 "" H 4850 725 50  0001 C CNN
	1    4850 725 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 5A2B1432
P 2925 2050
F 0 "#PWR02" H 2925 1900 50  0001 C CNN
F 1 "+5V" H 2925 2190 50  0000 C CNN
F 2 "" H 2925 2050 50  0001 C CNN
F 3 "" H 2925 2050 50  0001 C CNN
	1    2925 2050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 5A2B445E
P 850 2925
F 0 "#PWR03" H 850 2775 50  0001 C CNN
F 1 "+5V" H 850 3065 50  0000 C CNN
F 2 "" H 850 2925 50  0001 C CNN
F 3 "" H 850 2925 50  0001 C CNN
	1    850  2925
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 5A2B5128
P 850 4425
F 0 "#PWR04" H 850 4275 50  0001 C CNN
F 1 "+5V" H 850 4565 50  0000 C CNN
F 2 "" H 850 4425 50  0001 C CNN
F 3 "" H 850 4425 50  0001 C CNN
	1    850  4425
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 5A2B6440
P 850 6200
F 0 "#PWR05" H 850 6050 50  0001 C CNN
F 1 "+5V" H 850 6340 50  0000 C CNN
F 2 "" H 850 6200 50  0001 C CNN
F 3 "" H 850 6200 50  0001 C CNN
	1    850  6200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 5A2B712D
P 6525 5325
F 0 "#PWR06" H 6525 5175 50  0001 C CNN
F 1 "+5V" H 6525 5465 50  0000 C CNN
F 2 "" H 6525 5325 50  0001 C CNN
F 3 "" H 6525 5325 50  0001 C CNN
	1    6525 5325
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 5A2B77A9
P 8475 5100
F 0 "#PWR07" H 8475 4950 50  0001 C CNN
F 1 "+5V" H 8475 5240 50  0000 C CNN
F 2 "" H 8475 5100 50  0001 C CNN
F 3 "" H 8475 5100 50  0001 C CNN
	1    8475 5100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR08
U 1 1 5A2B79F1
P 10150 5175
F 0 "#PWR08" H 10150 5025 50  0001 C CNN
F 1 "+5V" H 10150 5315 50  0000 C CNN
F 2 "" H 10150 5175 50  0001 C CNN
F 3 "" H 10150 5175 50  0001 C CNN
	1    10150 5175
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 5A2B913D
P 10150 2550
F 0 "#PWR09" H 10150 2400 50  0001 C CNN
F 1 "+5V" H 10150 2690 50  0000 C CNN
F 2 "" H 10150 2550 50  0001 C CNN
F 3 "" H 10150 2550 50  0001 C CNN
	1    10150 2550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 5A2B93A8
P 10150 750
F 0 "#PWR010" H 10150 600 50  0001 C CNN
F 1 "+5V" H 10150 890 50  0000 C CNN
F 2 "" H 10150 750 50  0001 C CNN
F 3 "" H 10150 750 50  0001 C CNN
	1    10150 750 
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR011
U 1 1 5A2C3E5D
P 850 3075
F 0 "#PWR011" H 850 2825 50  0001 C CNN
F 1 "GND" H 850 2925 50  0001 C CNN
F 2 "" H 850 3075 50  0001 C CNN
F 3 "" H 850 3075 50  0001 C CNN
	1    850  3075
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR012
U 1 1 5A2C6F69
P 850 4575
F 0 "#PWR012" H 850 4325 50  0001 C CNN
F 1 "GND" H 850 4425 50  0001 C CNN
F 2 "" H 850 4575 50  0001 C CNN
F 3 "" H 850 4575 50  0001 C CNN
	1    850  4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  4550 950  4550
Wire Wire Line
	850  4450 950  4450
Wire Wire Line
	950  3050 850  3050
Wire Wire Line
	850  3050 850  3075
Wire Wire Line
	950  2950 850  2950
Wire Wire Line
	850  2950 850  2925
Wire Wire Line
	850  4450 850  4425
Wire Wire Line
	850  4575 850  4550
$Comp
L GND-RESCUE-Tardis #PWR013
U 1 1 5A2DE68C
P 850 6350
F 0 "#PWR013" H 850 6100 50  0001 C CNN
F 1 "GND" H 850 6200 50  0001 C CNN
F 2 "" H 850 6350 50  0001 C CNN
F 3 "" H 850 6350 50  0001 C CNN
	1    850  6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  6200 850  6225
Wire Wire Line
	850  6225 950  6225
Wire Wire Line
	850  6350 850  6325
Wire Wire Line
	850  6325 950  6325
$Comp
L GND-RESCUE-Tardis #PWR014
U 1 1 5A2E2BFF
P 6525 5475
F 0 "#PWR014" H 6525 5225 50  0001 C CNN
F 1 "GND" H 6525 5325 50  0001 C CNN
F 2 "" H 6525 5475 50  0001 C CNN
F 3 "" H 6525 5475 50  0001 C CNN
	1    6525 5475
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR015
U 1 1 5A2E316E
P 8475 5250
F 0 "#PWR015" H 8475 5000 50  0001 C CNN
F 1 "GND" H 8475 5100 50  0001 C CNN
F 2 "" H 8475 5250 50  0001 C CNN
F 3 "" H 8475 5250 50  0001 C CNN
	1    8475 5250
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR016
U 1 1 5A2E33B6
P 10150 5325
F 0 "#PWR016" H 10150 5075 50  0001 C CNN
F 1 "GND" H 10150 5175 50  0001 C CNN
F 2 "" H 10150 5325 50  0001 C CNN
F 3 "" H 10150 5325 50  0001 C CNN
	1    10150 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 5225 8475 5225
Wire Wire Line
	8475 5225 8475 5250
Wire Wire Line
	8600 5125 8475 5125
Wire Wire Line
	8475 5125 8475 5100
Wire Wire Line
	10150 5325 10150 5300
Wire Wire Line
	10150 5300 10275 5300
Wire Wire Line
	10150 5175 10150 5200
Wire Wire Line
	10150 5200 10275 5200
$Comp
L GND-RESCUE-Tardis #PWR017
U 1 1 5A2F48FD
P 7500 4075
F 0 "#PWR017" H 7500 3825 50  0001 C CNN
F 1 "GND" H 7500 3925 50  0001 C CNN
F 2 "" H 7500 4075 50  0001 C CNN
F 3 "" H 7500 4075 50  0001 C CNN
	1    7500 4075
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR018
U 1 1 5A2F93C3
P 6800 3275
F 0 "#PWR018" H 6800 3025 50  0001 C CNN
F 1 "GND" H 6800 3125 50  0001 C CNN
F 2 "" H 6800 3275 50  0001 C CNN
F 3 "" H 6800 3275 50  0001 C CNN
	1    6800 3275
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3275 6800 3250
$Comp
L GND-RESCUE-Tardis #PWR019
U 1 1 5A3025FE
P 10925 2675
F 0 "#PWR019" H 10925 2425 50  0001 C CNN
F 1 "GND" H 10925 2525 50  0001 C CNN
F 2 "" H 10925 2675 50  0001 C CNN
F 3 "" H 10925 2675 50  0001 C CNN
	1    10925 2675
	1    0    0    -1  
$EndComp
Wire Wire Line
	10925 2650 10925 2675
$Comp
L GND-RESCUE-Tardis #PWR020
U 1 1 5A30A76A
P 10950 875
F 0 "#PWR020" H 10950 625 50  0001 C CNN
F 1 "GND" H 10950 725 50  0001 C CNN
F 2 "" H 10950 875 50  0001 C CNN
F 3 "" H 10950 875 50  0001 C CNN
	1    10950 875 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 875  10950 850 
$Comp
L GND-RESCUE-Tardis #PWR021
U 1 1 5A30E597
P 6800 1475
F 0 "#PWR021" H 6800 1225 50  0001 C CNN
F 1 "GND" H 6800 1325 50  0001 C CNN
F 2 "" H 6800 1475 50  0001 C CNN
F 3 "" H 6800 1475 50  0001 C CNN
	1    6800 1475
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR022
U 1 1 5A3126EB
P 7450 2300
F 0 "#PWR022" H 7450 2050 50  0001 C CNN
F 1 "GND" H 7450 2150 50  0001 C CNN
F 2 "" H 7450 2300 50  0001 C CNN
F 3 "" H 7450 2300 50  0001 C CNN
	1    7450 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2300 7450 2275
Wire Wire Line
	6800 1475 6800 1450
Wire Wire Line
	6650 5350 6525 5350
Wire Wire Line
	6525 5350 6525 5325
Wire Wire Line
	6525 5475 6525 5450
Wire Wire Line
	6525 5450 6650 5450
$Comp
L +5V #PWR023
U 1 1 5A3667F5
P 3200 5925
F 0 "#PWR023" H 3200 5775 50  0001 C CNN
F 1 "+5V" H 3200 6065 50  0000 C CNN
F 2 "" H 3200 5925 50  0001 C CNN
F 3 "" H 3200 5925 50  0001 C CNN
	1    3200 5925
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR024
U 1 1 5A3667FB
P 3200 6075
F 0 "#PWR024" H 3200 5825 50  0001 C CNN
F 1 "GND" H 3200 5925 50  0001 C CNN
F 2 "" H 3200 6075 50  0001 C CNN
F 3 "" H 3200 6075 50  0001 C CNN
	1    3200 6075
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 6050 3200 6050
Wire Wire Line
	3200 6050 3200 6075
Wire Wire Line
	3300 5950 3200 5950
Wire Wire Line
	3200 5950 3200 5925
Wire Wire Line
	7500 4050 7500 4075
Wire Wire Line
	7250 4025 7250 4050
Wire Wire Line
	7700 4050 7700 4025
Wire Wire Line
	7250 3725 7250 3700
Wire Wire Line
	7700 3725 7700 3700
Connection ~ 7700 3700
Wire Wire Line
	7200 1925 7200 1900
Wire Wire Line
	7700 1925 7700 1900
Wire Wire Line
	1225 2075 1900 2075
Connection ~ 1875 2075
Text GLabel 7475 5350 2    60   Output ~ 0
uC_PTT
Wire Wire Line
	7425 5350 7475 5350
Text GLabel 1700 5350 2    60   Output ~ 0
uC_PTT
Wire Wire Line
	1700 5350 1500 5350
Text GLabel 5000 6825 2    60   Input ~ 0
~STBY
Wire Wire Line
	5000 6825 4875 6825
Wire Wire Line
	4275 4650 4400 4650
Text GLabel 4275 4650 0    60   Input ~ 0
PTT_OUT
$Comp
L GND-RESCUE-Tardis #PWR025
U 1 1 5A255D6A
P 4325 4850
F 0 "#PWR025" H 4325 4600 50  0001 C CNN
F 1 "GND" H 4325 4700 50  0001 C CNN
F 2 "" H 4325 4850 50  0001 C CNN
F 3 "" H 4325 4850 50  0001 C CNN
	1    4325 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4325 4850 4325 4825
Wire Wire Line
	4325 4825 4400 4825
Wire Wire Line
	4400 4300 4275 4300
Text GLabel 5350 2075 0    60   Input ~ 0
SPKR_OUT1_N
Text GLabel 1700 5450 2    60   Output ~ 0
Radio_PTT
Wire Wire Line
	1500 5450 1700 5450
Text GLabel 5925 7225 0    60   Output ~ 0
Radio_PTT
$Comp
L GND-RESCUE-Tardis #PWR026
U 1 1 5A2689C9
P 6250 7450
F 0 "#PWR026" H 6250 7200 50  0001 C CNN
F 1 "GND" H 6250 7300 50  0001 C CNN
F 2 "" H 6250 7450 50  0001 C CNN
F 3 "" H 6250 7450 50  0001 C CNN
	1    6250 7450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR027
U 1 1 5A268E8A
P 6250 6650
F 0 "#PWR027" H 6250 6500 50  0001 C CNN
F 1 "+5V" H 6250 6790 50  0000 C CNN
F 2 "" H 6250 6650 50  0001 C CNN
F 3 "" H 6250 6650 50  0001 C CNN
	1    6250 6650
	1    0    0    -1  
$EndComp
Text GLabel 6500 7000 2    60   Output ~ 0
PTT_OUT
$Comp
L R R14
U 1 1 5A26A421
P 6250 6825
F 0 "R14" H 6125 6825 50  0000 C CNN
F 1 "2.2k" V 6250 6825 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6180 6825 50  0001 C CNN
F 3 "" H 6250 6825 50  0001 C CNN
F 4 "5%" H 6350 6825 39  0000 C CNN "%"
	1    6250 6825
	-1   0    0    1   
$EndComp
Wire Wire Line
	6250 6650 6250 6675
Wire Wire Line
	6250 6975 6250 7025
Wire Wire Line
	6500 7000 6250 7000
Connection ~ 6250 7000
Wire Wire Line
	6250 7425 6250 7450
Wire Wire Line
	5925 7225 5950 7225
$Comp
L Q_NPN_EBC Q1
U 1 1 5A26F184
P 6150 7225
F 0 "Q1" H 6350 7275 50  0000 L CNN
F 1 "2N3904" H 6350 7175 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 6350 7325 50  0001 C CNN
F 3 "" H 6150 7225 50  0001 C CNN
	1    6150 7225
	1    0    0    -1  
$EndComp
Wire Notes Line
	5700 4750 5700 6450
Text Notes 6625 6325 0    60   ~ 12
PTT
Text GLabel 4100 2325 0    60   Input ~ 0
SPKR_OUT1_P_RAW
Wire Wire Line
	4100 2075 4125 2075
Wire Wire Line
	4125 2325 4100 2325
Text GLabel 4100 2825 0    60   Input ~ 0
SPKR_OUT1_P
Text GLabel 4100 3325 0    60   Input ~ 0
MIC_IN1_P
Text GLabel 4100 3575 0    60   Input ~ 0
MIC_IN2_P
Text GLabel 4100 3075 0    60   Input ~ 0
MIC_IN1_P_RAW
Wire Wire Line
	1875 2175 1875 2075
Text GLabel 4100 2075 0    60   Input ~ 0
SPKR_OUT1_N_RAW
Text GLabel 5350 2825 0    60   Input ~ 0
~STBY
Text GLabel 6850 3700 0    60   Input ~ 0
SPKR_OUT1_P
Text GLabel 5350 2325 0    60   Input ~ 0
MIC_IN1_N
Wire Wire Line
	6650 5675 6375 5675
$Comp
L GND #PWR028
U 1 1 5A58EB77
P 2400 2575
F 0 "#PWR028" H 2400 2325 50  0001 C CNN
F 1 "GND" H 2400 2425 50  0000 C CNN
F 2 "" H 2400 2575 50  0001 C CNN
F 3 "" H 2400 2575 50  0001 C CNN
	1    2400 2575
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 5A49AB0B
P 5700 850
F 0 "#PWR029" H 5700 600 50  0001 C CNN
F 1 "GND" H 5700 700 50  0000 C CNN
F 2 "" H 5700 850 50  0001 C CNN
F 3 "" H 5700 850 50  0001 C CNN
	1    5700 850 
	1    0    0    -1  
$EndComp
Text GLabel 6650 1000 0    60   Input ~ 0
MIC_IN1_P_RAW
$Comp
L GND #PWR030
U 1 1 5A4C46CA
P 5175 3175
F 0 "#PWR030" H 5175 2925 50  0001 C CNN
F 1 "GND" H 5175 3025 50  0000 C CNN
F 2 "" H 5175 3175 50  0001 C CNN
F 3 "" H 5175 3175 50  0001 C CNN
	1    5175 3175
	1    0    0    -1  
$EndComp
Text Label 2400 2525 0    60   ~ 0
GND
Text Label 850  3050 2    60   ~ 0
GND
Text Label 850  4550 2    60   ~ 0
GND
Text Label 850  6325 2    60   ~ 0
GND
Text Label 3200 6050 2    60   ~ 0
GND
Text Label 4325 4825 2    60   ~ 0
GND
Text Label 6525 5450 2    60   ~ 0
GND
Text Label 8475 5225 2    60   ~ 0
GND
Text Label 6250 7450 2    60   ~ 0
GND
Text Label 7500 4050 0    60   ~ 0
GND
Text Label 7450 2275 0    60   ~ 0
GND
Text Label 6800 1450 0    60   ~ 0
GND
Text Label 6800 3250 0    60   ~ 0
GND
Text Label 5700 750  0    60   ~ 0
GND
Text Label 5175 3150 2    60   ~ 0
GND
Text Label 10950 850  0    60   ~ 0
GND
Text Label 10925 2650 0    60   ~ 0
GND
Text Label 10150 5300 2    60   ~ 0
GND
Wire Wire Line
	2900 2075 2925 2075
Text GLabel 4100 2575 0    60   Input ~ 0
SPKR_OUT2_P_RAW
Text GLabel 6375 5675 0    60   Input ~ 0
SPKR_OUT2_P_RAW
NoConn ~ 1500 5550
NoConn ~ 1500 7125
NoConn ~ 1500 7225
NoConn ~ 1500 7325
$Comp
L CONN_01X01 J1
U 1 1 5A52F170
P 4325 2075
F 0 "J1" H 4325 2175 50  0000 C CNN
F 1 "CONN_01X01" H 4325 2000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 2075 50  0001 C CNN
F 3 "" H 4325 2075 50  0001 C CNN
	1    4325 2075
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 J2
U 1 1 5A53225A
P 4325 2325
F 0 "J2" H 4325 2425 50  0000 C CNN
F 1 "CONN_01X01" H 4325 2250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 2325 50  0001 C CNN
F 3 "" H 4325 2325 50  0001 C CNN
	1    4325 2325
	1    0    0    -1  
$EndComp
Text GLabel 5350 2575 0    60   Input ~ 0
MIC_IN2_N
$Comp
L CONN_01X01 J3
U 1 1 5A53A7FE
P 4325 2575
F 0 "J3" H 4325 2675 50  0000 C CNN
F 1 "CONN_01X01" H 4325 2500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 2575 50  0001 C CNN
F 3 "" H 4325 2575 50  0001 C CNN
	1    4325 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4125 2575 4100 2575
$Comp
L CONN_01X01 J6
U 1 1 5A53E1AF
P 4325 3325
F 0 "J6" H 4325 3425 50  0000 C CNN
F 1 "CONN_01X01" H 4325 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 3325 50  0001 C CNN
F 3 "" H 4325 3325 50  0001 C CNN
	1    4325 3325
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3325 4125 3325
$Comp
L CONN_01X01 J7
U 1 1 5A54109E
P 4325 3575
F 0 "J7" H 4325 3675 50  0000 C CNN
F 1 "CONN_01X01" H 4325 3500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 3575 50  0001 C CNN
F 3 "" H 4325 3575 50  0001 C CNN
	1    4325 3575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4125 3575 4100 3575
$Comp
L CONN_01X01 J5
U 1 1 5A541D37
P 4325 3075
F 0 "J5" H 4325 3175 50  0000 C CNN
F 1 "CONN_01X01" H 4325 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 3075 50  0001 C CNN
F 3 "" H 4325 3075 50  0001 C CNN
	1    4325 3075
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3075 4125 3075
$Comp
L CONN_01X01 J4
U 1 1 5A54277B
P 4325 2825
F 0 "J4" H 4325 2925 50  0000 C CNN
F 1 "CONN_01X01" H 4325 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4325 2825 50  0001 C CNN
F 3 "" H 4325 2825 50  0001 C CNN
	1    4325 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2825 4125 2825
$Comp
L CONN_01X01 J8
U 1 1 5A545BBF
P 5575 2075
F 0 "J8" H 5575 2175 50  0000 C CNN
F 1 "CONN_01X01" H 5575 2000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5575 2075 50  0001 C CNN
F 3 "" H 5575 2075 50  0001 C CNN
	1    5575 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2075 5375 2075
$Comp
L CONN_01X01 J9
U 1 1 5A547D23
P 5575 2325
F 0 "J9" H 5575 2425 50  0000 C CNN
F 1 "CONN_01X01" H 5575 2250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5575 2325 50  0001 C CNN
F 3 "" H 5575 2325 50  0001 C CNN
	1    5575 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2325 5375 2325
$Comp
L CONN_01X01 J10
U 1 1 5A5486B2
P 5575 2575
F 0 "J10" H 5575 2675 50  0000 C CNN
F 1 "CONN_01X01" H 5575 2500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5575 2575 50  0001 C CNN
F 3 "" H 5575 2575 50  0001 C CNN
	1    5575 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2575 5375 2575
$Comp
L CONN_01X01 J11
U 1 1 5A54A37E
P 5575 2825
F 0 "J11" H 5575 2925 50  0000 C CNN
F 1 "CONN_01X01" H 5575 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5575 2825 50  0001 C CNN
F 3 "" H 5575 2825 50  0001 C CNN
	1    5575 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2825 5375 2825
$Comp
L CONN_01X01 J12
U 1 1 5A54C8EF
P 5575 3100
F 0 "J12" H 5575 3200 50  0000 C CNN
F 1 "CONN_01X01" H 5575 3025 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5575 3100 50  0001 C CNN
F 3 "" H 5575 3100 50  0001 C CNN
	1    5575 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5175 3175 5175 3100
Wire Wire Line
	5175 3100 5375 3100
$Comp
L CONN_01X01 J14
U 1 1 5A552977
P 6600 1900
F 0 "J14" H 6600 2000 50  0000 C CNN
F 1 "CONN_01X01" H 6600 1825 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 6600 1900 50  0001 C CNN
F 3 "" H 6600 1900 50  0001 C CNN
	1    6600 1900
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J13
U 1 1 5A552C24
P 6550 2800
F 0 "J13" H 6550 2900 50  0000 C CNN
F 1 "CONN_01X01" H 6550 2725 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 6550 2800 50  0001 C CNN
F 3 "" H 6550 2800 50  0001 C CNN
	1    6550 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 4450 4275 4450
$EndSCHEMATC
