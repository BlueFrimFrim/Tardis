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
Sheet 8 8
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
L TS4990IST U8
U 1 1 5A23E919
P 5200 2575
F 0 "U8" H 5150 3025 60  0000 C CNN
F 1 "TS4990IST" H 5325 1875 60  0000 C CNN
F 2 "Housings_SSOP:MSOP-8_3x3mm_Pitch0.65mm" H 4500 3150 60  0001 C CNN
F 3 "" H 4500 3150 60  0001 C CNN
	1    5200 2575
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 5A23E92A
P 4250 2275
F 0 "C16" V 4200 2075 50  0000 L CNN
F 1 "100nF" V 4300 2000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4288 2125 50  0001 C CNN
F 3 "" H 4250 2275 50  0001 C CNN
F 4 "5%" V 4200 2375 39  0000 C CNN "%"
	1    4250 2275
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 2275 4900 2275
Wire Wire Line
	4400 2275 4450 2275
$Comp
L C C18
U 1 1 5A23E93E
P 4600 2875
F 0 "C18" V 4550 2675 50  0000 L CNN
F 1 "1uF" V 4650 2675 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4638 2725 50  0001 C CNN
F 3 "" H 4600 2875 50  0001 C CNN
F 4 "5%" V 4550 2975 39  0000 C CNN "%"
	1    4600 2875
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 2500 4800 2875
Wire Wire Line
	4750 2875 4900 2875
Connection ~ 4800 2875
$Comp
L C C22
U 1 1 5A23E94C
P 6250 3125
F 0 "C22" V 6300 3175 50  0000 L CNN
F 1 "1uF" V 6200 3175 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6288 2975 50  0001 C CNN
F 3 "" H 6250 3125 50  0001 C CNN
F 4 "5%" V 6300 3025 39  0000 C CNN "%"
	1    6250 3125
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3975 2275 4100 2275
Wire Wire Line
	6100 2425 6000 2425
Wire Wire Line
	6000 2275 6100 2275
$Comp
L R R61
U 1 1 5A23E96E
P 5200 1725
F 0 "R61" V 5300 1800 50  0000 C CNN
F 1 "20k" V 5200 1725 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 1725 50  0001 C CNN
F 3 "" H 5200 1725 50  0001 C CNN
F 4 "1%" V 5300 1650 39  0000 C CNN "%"
	1    5200 1725
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 2275 4800 1725
Wire Wire Line
	4800 1725 5050 1725
Connection ~ 4800 2275
Wire Wire Line
	5350 1725 6050 1725
Wire Wire Line
	6050 1725 6050 2275
Connection ~ 6050 2275
$Comp
L R R59
U 1 1 5A23E97C
P 4600 2275
F 0 "R59" V 4700 2350 50  0000 C CNN
F 1 "20k" V 4600 2275 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4530 2275 50  0001 C CNN
F 3 "" H 4600 2275 50  0001 C CNN
F 4 "1%" V 4700 2200 39  0000 C CNN "%"
	1    4600 2275
	0    -1   -1   0   
$EndComp
$Comp
L TS4990IST U9
U 1 1 5A23E993
P 5225 4975
F 0 "U9" H 5175 5425 60  0000 C CNN
F 1 "TS4990IST" H 5350 4275 60  0000 C CNN
F 2 "Housings_SSOP:MSOP-8_3x3mm_Pitch0.65mm" H 4525 5550 60  0001 C CNN
F 3 "" H 4525 5550 60  0001 C CNN
	1    5225 4975
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 5A23E9A4
P 4275 4675
F 0 "C17" V 4225 4475 50  0000 L CNN
F 1 "100nF" V 4325 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4313 4525 50  0001 C CNN
F 3 "" H 4275 4675 50  0001 C CNN
F 4 "5%" V 4225 4775 39  0000 C CNN "%"
	1    4275 4675
	0    1    1    0   
$EndComp
Wire Wire Line
	4775 4675 4925 4675
Wire Wire Line
	4425 4675 4475 4675
$Comp
L C C19
U 1 1 5A23E9B8
P 4625 5275
F 0 "C19" V 4575 5075 50  0000 L CNN
F 1 "1uF" V 4675 5075 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4663 5125 50  0001 C CNN
F 3 "" H 4625 5275 50  0001 C CNN
F 4 "5%" V 4575 5375 39  0000 C CNN "%"
	1    4625 5275
	0    1    1    0   
$EndComp
Wire Wire Line
	4825 4900 4825 5275
Wire Wire Line
	4775 5275 4925 5275
Connection ~ 4825 5275
$Comp
L C C23
U 1 1 5A23E9C6
P 6275 5525
F 0 "C23" V 6225 5325 50  0000 L CNN
F 1 "1uF" V 6325 5325 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6313 5375 50  0001 C CNN
F 3 "" H 6275 5525 50  0001 C CNN
F 4 "5%" V 6225 5625 39  0000 C CNN "%"
	1    6275 5525
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 4675 4125 4675
Wire Wire Line
	6125 4825 6025 4825
Wire Wire Line
	6025 4675 6125 4675
$Comp
L R R62
U 1 1 5A23E9E5
P 5200 4075
F 0 "R62" V 5300 4150 50  0000 C CNN
F 1 "20k" V 5200 4075 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 4075 50  0001 C CNN
F 3 "" H 5200 4075 50  0001 C CNN
F 4 "1%" V 5300 4000 39  0000 C CNN "%"
	1    5200 4075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4825 4075 4825 4675
Connection ~ 4825 4675
Wire Wire Line
	6075 4075 6075 4675
Connection ~ 6075 4675
$Comp
L R R60
U 1 1 5A23E9F3
P 4625 4675
F 0 "R60" V 4725 4750 50  0000 C CNN
F 1 "20k" V 4625 4675 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4555 4675 50  0001 C CNN
F 3 "" H 4625 4675 50  0001 C CNN
F 4 "1%" V 4725 4600 39  0000 C CNN "%"
	1    4625 4675
	0    -1   -1   0   
$EndComp
Text HLabel 6100 2275 2    60   Output ~ 0
MIC_IN_P
Text HLabel 6100 2425 2    60   Output ~ 0
MIC_IN_N
Text HLabel 6125 4675 2    60   Output ~ 0
SPKR_OUT_P
Text HLabel 6125 4825 2    60   Output ~ 0
SPKR_OUT_N
Text HLabel 2175 2175 0    60   Input ~ 0
GND
$Comp
L GND-RESCUE-Tardis #PWR82
U 1 1 5A35F2E4
P 2325 2200
F 0 "#PWR82" H 2325 1950 50  0001 C CNN
F 1 "GND" H 2325 2050 50  0001 C CNN
F 2 "" H 2325 2200 50  0001 C CNN
F 3 "" H 2325 2200 50  0001 C CNN
	1    2325 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2175 2175 2325 2175
Wire Wire Line
	2325 2175 2325 2200
$Comp
L +5V #PWR81
U 1 1 5A35F2EC
P 2325 2050
F 0 "#PWR81" H 2325 1900 50  0001 C CNN
F 1 "+5V" H 2325 2190 50  0000 C CNN
F 2 "" H 2325 2050 50  0001 C CNN
F 3 "" H 2325 2050 50  0001 C CNN
	1    2325 2050
	1    0    0    -1  
$EndComp
Text HLabel 2175 2075 0    60   Input ~ 0
5V
Wire Wire Line
	2175 2075 2325 2075
Wire Wire Line
	2325 2075 2325 2050
$Comp
L +5V #PWR87
U 1 1 5A35F319
P 6425 2975
F 0 "#PWR87" H 6425 2825 50  0001 C CNN
F 1 "+5V" H 6425 3115 50  0000 C CNN
F 2 "" H 6425 2975 50  0001 C CNN
F 3 "" H 6425 2975 50  0001 C CNN
	1    6425 2975
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR83
U 1 1 5A35F35A
P 4350 3000
F 0 "#PWR83" H 4350 2750 50  0001 C CNN
F 1 "GND" H 4350 2850 50  0001 C CNN
F 2 "" H 4350 3000 50  0001 C CNN
F 3 "" H 4350 3000 50  0001 C CNN
	1    4350 3000
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR85
U 1 1 5A35F491
P 6025 3225
F 0 "#PWR85" H 6025 2975 50  0001 C CNN
F 1 "GND" H 6025 3075 50  0001 C CNN
F 2 "" H 6025 3225 50  0001 C CNN
F 3 "" H 6025 3225 50  0001 C CNN
	1    6025 3225
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR88
U 1 1 5A35F52A
P 6450 5375
F 0 "#PWR88" H 6450 5225 50  0001 C CNN
F 1 "+5V" H 6450 5515 50  0000 C CNN
F 2 "" H 6450 5375 50  0001 C CNN
F 3 "" H 6450 5375 50  0001 C CNN
	1    6450 5375
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR84
U 1 1 5A35F5FB
P 4375 5425
F 0 "#PWR84" H 4375 5175 50  0001 C CNN
F 1 "GND" H 4375 5275 50  0001 C CNN
F 2 "" H 4375 5425 50  0001 C CNN
F 3 "" H 4375 5425 50  0001 C CNN
	1    4375 5425
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Tardis #PWR86
U 1 1 5A35F714
P 6050 5650
F 0 "#PWR86" H 6050 5400 50  0001 C CNN
F 1 "GND" H 6050 5500 50  0001 C CNN
F 2 "" H 6050 5650 50  0001 C CNN
F 3 "" H 6050 5650 50  0001 C CNN
	1    6050 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2500 4900 2500
Wire Wire Line
	6000 3000 6425 3000
Wire Wire Line
	6425 2975 6425 3125
Wire Wire Line
	6425 3125 6400 3125
Wire Wire Line
	6000 3125 6100 3125
Wire Wire Line
	6025 3225 6025 3125
Connection ~ 6025 3125
Connection ~ 6425 3000
Wire Wire Line
	6025 5400 6450 5400
Wire Wire Line
	6450 5375 6450 5525
Wire Wire Line
	6450 5525 6425 5525
Wire Wire Line
	6025 5525 6125 5525
Connection ~ 6450 5400
Wire Wire Line
	6050 5525 6050 5650
Connection ~ 6050 5525
Wire Wire Line
	4925 4900 4825 4900
$Comp
L C C20
U 1 1 5A24E9E5
P 5200 1925
F 0 "C20" V 5125 1750 50  0000 L CNN
F 1 "1uF" V 5250 1725 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5238 1775 50  0001 C CNN
F 3 "" H 5200 1925 50  0001 C CNN
F 4 "5%" V 5150 2025 39  0000 C CNN "%"
	1    5200 1925
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 1925 4975 1925
Wire Wire Line
	4975 1925 4975 1725
Connection ~ 4975 1725
Wire Wire Line
	5350 1925 5450 1925
Wire Wire Line
	5450 1925 5450 1725
Connection ~ 5450 1725
Text Notes 5250 2025 0    60   ~ 0
DNP
Wire Notes Line
	4950 1800 5475 1800
Wire Notes Line
	5475 1800 5475 2050
Wire Notes Line
	5475 2050 4950 2050
Wire Notes Line
	4950 2050 4950 1800
Text HLabel 5100 3450 2    60   Input ~ 0
~STBY
Wire Wire Line
	4900 3125 4875 3125
Wire Wire Line
	4875 3125 4875 3450
Wire Wire Line
	4875 3450 5100 3450
Wire Wire Line
	4350 3000 4350 2875
Wire Wire Line
	4350 2875 4450 2875
Wire Wire Line
	4375 5425 4375 5275
Wire Wire Line
	4375 5275 4475 5275
Text HLabel 5125 5850 2    60   Input ~ 0
~STBY
Wire Wire Line
	4925 5525 4900 5525
Wire Wire Line
	4900 5525 4900 5850
Wire Wire Line
	4900 5850 5125 5850
$Comp
L C C21
U 1 1 5A25010F
P 5200 4275
F 0 "C21" V 5125 4100 50  0000 L CNN
F 1 "1uF" V 5250 4075 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5238 4125 50  0001 C CNN
F 3 "" H 5200 4275 50  0001 C CNN
F 4 "5%" V 5150 4375 39  0000 C CNN "%"
	1    5200 4275
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 4275 4975 4275
Wire Wire Line
	4975 4275 4975 4075
Wire Wire Line
	5350 4275 5450 4275
Wire Wire Line
	5450 4275 5450 4075
Text Notes 5250 4375 0    60   ~ 0
DNP
Wire Notes Line
	4950 4150 5475 4150
Wire Notes Line
	5475 4150 5475 4400
Wire Notes Line
	5475 4400 4950 4400
Wire Notes Line
	4950 4400 4950 4150
Wire Wire Line
	4825 4075 5050 4075
Connection ~ 4975 4075
Wire Wire Line
	5350 4075 6075 4075
Connection ~ 5450 4075
Text Label 2325 2175 0    60   ~ 0
GND
Text Label 4350 2875 2    60   ~ 0
GND
Text Label 6025 3125 2    60   ~ 0
GND
Text Label 6050 5525 2    60   ~ 0
GND
Text Label 4375 5275 2    60   ~ 0
GND
$Comp
L CONN_01X01 J16
U 1 1 5A55D9A8
P 3800 4675
F 0 "J16" H 3800 4775 50  0000 C CNN
F 1 "CONN_01X01" H 3800 4600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3800 4675 50  0001 C CNN
F 3 "" H 3800 4675 50  0001 C CNN
	1    3800 4675
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J15
U 1 1 5A55DA84
P 3775 2275
F 0 "J15" H 3775 2375 50  0000 C CNN
F 1 "CONN_01X01" H 3775 2200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3775 2275 50  0001 C CNN
F 3 "" H 3775 2275 50  0001 C CNN
	1    3775 2275
	-1   0    0    1   
$EndComp
$EndSCHEMATC
