#include <stdio.h>
#include "lab3Header.h"

int main()
{
	
	float radSphere, radCylinder, hCylinder;
	float surface, volSphere, volCyl, sum, angle;
	int numValues, numAngles;
	double sineCalc;
	
	
	printf("Enter the radius of the spehere: ");
	scanf("%f" , &radSphere);
	
	sphere(radSphere, &surface, &volSphere);
	
	printf("\nThe volume of the sphere is : %f\n" , volSphere);
	printf("\nThe surface area of the sphere is : %f\n" , surface);


	printf("\nEnter the radius of the cylinder: ");
	scanf("%f", &radCylinder);
	printf("\nEnter the height of the cylinder: ");
	scanf("%f", &hCylinder);
	
	volCyl = volCylinder(radCylinder, &hCylinder);
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
	
	sum = sumFloats(x, numValues);
	
	printf("The sum of the %d floating point values is: %f \n" , numValues, sum);
	
	printf("How many angles do you want to calculate the sine of : ");
	scanf("%d" , &numAngles);
	
	for(int j = 0; j < numAngles; j++)
	{ 
	
		printf("\nEnter the angle in degrees to calculate the sine : ");
		scanf("%f" , &angle);
		
		sineCalc = sine(angle);
	
		printf("\nThe sine of the angle is : %lf radians\n\n" , sineCalc);
		
	}
	
	return 0;
}
