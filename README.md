# GIS (Geographic Information System)
Chandler Neece

COP 3530 - Data Structures and Algorithms - Spring 2022

Geographic information system program for determining which polygon a user-specified point lies within. 

# Usage
##### Makefile
The program can be compiled by using ```make main``` and subsequently ran by using ```./main```

##### Sample Input Data
There is sample data contained in simple-ploygons.txt and more complicated set of polygons that are contained in polygons.txt

##### Sample Run of Program
```
Please enter the file with the polygon data: bad-file-name.zz
Invalid file name!
Please enter the file with the polygon data: simple-polygons.txt

Coordinates of query point (non-integer quits)
	x: 1
	y: 1
Query point is inside: squareParcel

Coordinates of query point (non-integer quits)
	x: 3
	y: 3
Query point is inside: wideRectangleParcel

Coordinates of query point (non-integer quits)
	x: 7
	y: 7
Query point is inside: Query point not present in any known parcel

Coordinates of query point (non-integer quits)
	x: quit

Thank you for using the program!
```
