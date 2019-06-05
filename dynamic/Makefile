	

 
testDynamic: lab3Dynamic.o libLab3Calculations.so
	gcc -lm -o testDynamic lab3Dynamic.c -L. -lLab3Calculations 

lab3Dynamic.o: lab3Files/lab3Dynamic.c
	gcc -c -o lab3Dynamic.o	lab3Files/lab3Dynamic.c

lab3Calculations.o: lab3Files/lab3Calculations.c
	$gcc -fPIC -c -o lab3Calculations.o lab3Calculations.c

libLab3Calculations.so: lab3Calculations.o
	gcc -shared lab3Calculations.o -o libLab3Calculations.so


export LD_LIBRARY_PATH=./
