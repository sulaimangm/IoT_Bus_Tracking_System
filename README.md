# Bus Tracking System
Bus Tracking System, created to track the location of the buses and to manage the schedule.The main goal of proposed system is to improve bus system by adding necessary features like accurate timings, correct bus number and moreover adding a GPS tracker into it. Many cities have found that GPS tracking system not only improves the efficiency of city bus operation, but also help commuters to take advantage of this bus system.

#Benifits for Passenger
Riders benefit form an advanced GPS bus tracking system in many ways. Shivering in the freezing cold in the winter is a thing of the past with a fleet tracking. GPS system that contains real-time alerts, as is sweating bullets on a hot summer day while waiting on a delayed bus. Bus riders waste less time, resulting in better planning of their schedules and enabling them to get more done. Real time bus tracking is also beneficial to college students who attend colleges with large campuses. With a bus tracking system, they can spend more time studying, or sleeping, rather than waiting on a delayed bus. Spending less time waiting for a bus, may improve student safety as well.
Bus tracking lets you know where your vehicles are at all times. You'll know if a vehicle failed to follow its schedule route. When a bus fails to leave or return when it’s scheduled to, alerts can be made to notify potential riders of a delay. Finally, GPS fleet vehicle tracking also helps to monitor unauthorized use of a bus, excessive speeding and unnecessary idling, all of which impact profits.

#Benefits of Bus maintanance Organization:
Tracking current location and predicting the time of arrival of the bus will have great effects in increasing the number of people using the buses. It will also help the bus management system to schedule the timings properly and maintain it.

#GPS Tracking System
A Global Positioning System, also known as GPS, is a system designed to help navigate on the Earth, in the air, and on water. A GPS receiver shows where it is. It may also show how fast it is moving, which direction it is going, how high it is, and maybe how fast it is going up or down. Many GPS receivers have information about places. PS’s for automobiles have travel data like road maps, hotels, restaurants, and service stations. GPSs for boats contain nautical charts of harbors, marinas, shallow water, rocks, and waterways. Other GPS receivers are made for air navigation, hiking and backpacking, bicycling, or many other activities. The majority are in smartphones.
GPS tracking unit is a device normally carried by a moving person or vehicle, that uses the global positioning system to determine and track its precise position, the recorded data can be kept with tracking unit or to a central location of database or an internet-connected computer, using a cellular(GPRS or SMS),or satellite modem embedded in the unit. This allows the asset’s location to be displayed on map backdrop either in real time or when analysing the track later using GPS tracking software. Data tracking software is available for smartphones with GPS capability.

Hardware Requirements:
NodeMCU
GPS Module

Software Requirements:
Arduino IDE
Blynk

Design:
GPS Tracker --> NodeMCU --> Blynk Cloud Server --> Blynk Mobile Application

The Implementation principle is given as below:
•	The NODEMCU has a built in Wi-Fi which will be connected to the phone or any hotspot. 
•	The GPS module is connected to the NODEMCU as shown in the pin diagram below.
GPS Module	NODEMCU
  GND	        GND
  Tx	        D2
  Rx	        D1
  Vcc	        3.3v

•	The power can be supplied to the NODEMCU using a laptop cable or a 3.3v battery supply.
•	The GPS receives position from satellites and sends data to the NODEMCU.
•	NODEMCU using Wi-Fi connects to the Blynk server.
•	Blynk app fetched data from Blynk server and pinpoints location in the inbuilt app.

