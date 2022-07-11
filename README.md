# An Agro-tech-project
The project sets a meteorological measurement system to a 15*6.5*3 greenhouse parameter on 14 points
The project's product is:
- A time-changing 2D heatmap of a 2D sensor array (a greenhouse's main wall, for this experiment) (measuring T, RH, and calculation VPD)

![a snippet from the gif](https://user-images.githubusercontent.com/101636430/177527053-d48cd177-4625-4e7a-b8b3-82157b17210e.png)

Components list:

Electronics:
- 7 esp32 microprocessors
- 7DS18B20 Temperature Sensor mounted on a water-proof mount and 1.5 m cable
- 7 SHT31 Temperature & Humidity Sensor
- 7 breadboards
- 4.7k Ohm resistors
- Jumper wires

Hardware:
- Electric wires
- Electric power supply (5V)
- ventalized electric boxes to shade sensors 

Software and data analysis:
- Two codes were used on the esp32 (written in C++).
	1) To find the address of the DS18B20 sensor
	2) To program the sensors to measure and communicate with a ‘thinkspeak’ cloud via WiFi
- Data analysis and visualization were done in python, and include 3 codes:
	1) 3D visualization of the greenhouse
	2) data importing and organizing
	3) 2D interpolation and extrapolation of the data to each face of the greenhouse (east and west). Visualization through a heatmap, the time dimension was animated using a GIF file.


Notes on the code:
- Two points (0,3.25,3) and (15,3.25,3) were extrapolated using the other points on the roof, to create a rectangular data set to interpolate from.
- sensor 3 data was irrelevant, and therefore replaced by the closest sensor.
-the minimum and maximum values for the heat map were set by the minimum and maximum values of sensor 4 and sensor 1.
 
how to install:
1) connect all the electronics as shown in the pictures.
![wiring of a single esp32](https://user-images.githubusercontent.com/101636430/177519766-95fc8418-0188-458b-b3d0-ff35753a130a.jpg)


2) load the code to the esp32 using Arduino-make sure you get the address for the DS18B20 sensor
3)  make sure that the sensors connect to the cloud and transmit the data to the correct channels.
4) chain all esp32’s to each other, and to the 5V power supply, then install on the wall.
![image](https://user-images.githubusercontent.com/101636430/178216996-10d3ca53-b73d-445f-8e0a-25d8068287fe.png)
![IMG-20220706-WA0013](https://user-images.githubusercontent.com/101636430/178217241-0358012e-1d42-4135-ae17-eccf514ebce1.jpg)


How to process:
1) Run ‘data processing’
2) Run ‘2D modeling’ (might take some time to run)


Things to improve in future versions:
- A symmetrical sensor placement would improve interpolation.
- 3D modeling considering the roof as a separate surface, would improve viability.
- Add a time-controlling slider to the animation, would help better analyze the results. 
