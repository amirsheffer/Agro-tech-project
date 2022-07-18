

# An Agro-tech-project
The project sets a meteorological measurement system to a greenhouse on 14 points
The project's product is:
- A time-changing 2D heatmap of a 2D sensor array (a greenhouse's main wall, for this experiment) (measuring T, RH, and calculation VPD)

![a snippet from the gif](https://user-images.githubusercontent.com/101636430/177527053-d48cd177-4625-4e7a-b8b3-82157b17210e.png)
Link to the whole time lapse heatmap: https://youtu.be/TZ94sUR4VJI

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
4) chain all esp32’s to each other, and the 5V power supply, then install them on the wall.
![image](https://user-images.githubusercontent.com/101636430/178216996-10d3ca53-b73d-445f-8e0a-25d8068287fe.png)
![IMG-20220706-WA0013](https://user-images.githubusercontent.com/101636430/178217241-0358012e-1d42-4135-ae17-eccf514ebce1.jpg)


How to process:
1) Run ‘data processing’
2) Run ‘2D modeling’ (might take some time to run)

Short data analysis:
- Night-time temperature is uniform throughout the sensors.
- Temperature is greatly influenced by shading. Eastern temperatures are hot from the morning to noon, western temperatures are high from afternoon to sunset.
- The southern wall has a wet mattress cooling system, in both cases, it is visible that the southern side is cooler than the northern one.
Things to improve in future versions:
- A symmetrical sensor placement would improve interpolation.
- 3D modeling considering the roof as a separate surface, would improve viability.
- Add a time-controlling slider to the animation, would help better analyze the results. 


![IMG-20220711-WA0021](https://user-images.githubusercontent.com/101636430/178229690-c706cca7-0a67-4061-8db6-bbfd09f1a318.jpg)
