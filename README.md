## Temperature-Monitoring-System

#My first freelancing project is completed


Every living organism has different ideal temperature levels. For the human being, the ideal environmental temperature is between 22 Celsius & 25 Celsius. Different animals need different temperature levels to keep healthy life. Electronic devices like servers should be kept in specific temperatures.  This project introduces a simulation for a temperature monitoring system that can be used in different areas.  It will display the temperature of the place needed to be monitored. PICSimLab software will be used for the simulation.



-Project Design:

LM35 is connected to the PIC16F877A microcontroller through one of its ADC channels. A 16x2 LCD and an RGB LED are connected to one of the port’s bits present in the microcontroller.  



-Project Operation:

LM35 will measure the temperature and send it through the ADC channel of the microcontroller. The microcontroller will, later on, display the measured temperature through the LCD. If the temperature is less than 20 °C the RGB will display a blue light. If the temperature is between 20 °C and 33 °C the BRG will display a green light. Finally, if the temperature is greater than 33 °C the color of RGB will change to red.

-Tools
MikroC
PICsim Lab

All related files for this project can be found here: 
