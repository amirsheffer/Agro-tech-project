# An Agro-tech-project
The project sets a meteorological measurement system to a 15*6.5*3 greenhouse parameter on 14 points
The project's product is:
- A time-changing 2D heatmap of the greenhouse's main wall (measuring T, RH, and calculation VPD), the western and eastern ones.

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
 
Things to improve in future versions:
- A symmetrical sensor placement would improve interpolation.
- 3D modeling considering the roof as a separate surface
- Add a time-controlling slider to the animation, to help better analyze the results. 
