#include <stdio.h>
#include <dlfcn.h>
#include "lab3Header.h"
#include <stdlib.h>

int main()
{
	float radSphere, radCylinder, hCylinder;
	float surface, volSphere, volCyl, sum, angle;
	int numValues, numAngles;
	double sineCalc;
	void *handle; 
	char *err;
	
	void (*sphere_d)();
	float(*volCylinder_d)();
	float(*sumFloats_d)();
	//int(*fact_d)();
	double(*sine_d)();
	
	handle = dlopen("./libLab3Calculations.so", RTLD_LAZY);
	if(handle ==(void*)0)
	{
		fputs(dlerror(), stderr);
		exit(-1);
		
	}
	
	//check availability of dynamic functions
	
	sphere_d = dlsym(handle, "sphere");
	err = dlerror();
	if(err != NULL)
	{
		fputs(err, stderr);
		exit(-1);
	}
	volCylinder_d = dlsym(handle, "volCylinder");
	err = dlerror();
	if(err != NULL)
	{
		fputs(err, stderr);
		exit(-1);
	}
	sumFloats_d = dlsym(handle, "sumFloats");
	err = dlerror();
	if(err != NULL)
	{
		fputs(err, stderr);
		exit(-1);
	}
	/*
	fact_d = dlsym(handle, "fact");
	err = dlerror();
	if(err != NULL)
	{
		fputs(err, stderr);
		exit(-1);
	}
	* */
	sine_d = dlsym(handle, "sine");
	err = dlerror();
	if(err != NULL)
	{
		fputs(err, stderr);
		exit(-1);
	}
	
	
	printf("Enter the radius of the spehere: ");
	scanf("%f" , &radSphere);
	
	(*sphere_d)(radSphere, &surface, &volSphere);
	
	printf("\nThe volume of the sphere is : %f\n" , volSphere);
	printf("\nThe surface area of the sphere is : %f\n" , surface);


	printf("\nEnter the radius of the cylinder: ");
	scanf("%f", &radCylinder);
	printf("\nEnter the height of the cylinder: ");
	scanf("%f", &hCylinder);
	
	volCyl = (*volCylinder_d)(radCylinder, &hCylinder);
	printf("\nThe volume of the cylinder is : %f\n" , volCyl);
	 
	printf("\nEnter the number of floating point values to add up : ");
	scanf("%d" , &numValues);
	
	float x[numValues];
	
	for (int j = 0; j < numValues; j++)
	{
		printf("\nEnter value %d : " , j + 1);
		scanf("%f" , &x[j]);
		
	}
	printf("\nThe values you entered unsorted : \n");
	for (int j = 0; j < numValues; j++)
	{
		printf("%f\n" ,x[j]);
		
	}
	
	sum = (*sumFloats_d)(x, numValues);
	
	printf("The sum of the %d floating point values is: %f \n" , numValues, sum);
	
	printf("How many angles to calculate the sine of : ");
	scanf("%d" , &numAngles);
	
	for(int j = 0; j < numAngles; j++)
	{ 
	
		printf("\nEnter the angle in degrees to calculate the sine : ");
		scanf("%f" , &angle);
		
		sineCalc = (*sine_d)(angle);
	
		printf("\nThe sine of the angle is : %lf radians\n\n" , sineCalc);
		
	}
	
	dlclose(handle);
	
	return 0;
}
