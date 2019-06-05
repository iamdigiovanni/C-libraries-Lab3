#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

float pi = M_PI;


int fact(int n);

void sphere(float radius, float *surface, float *volume)
{
	
	*surface = 4 * pi * (pow(radius, 2));
	*volume = (4.0/3.0) * pi * (pow(radius, 3)); 
}

float volCylinder(float radius, float *height)
{
	float volume;
	volume = pi * radius * radius * *height;
	return (volume);
	
}

float sumFloats(float x[], int numFloats) 
{
	
	int j, k, pt;
	float sum = 0;
	float temp;
	
	for(j = 0; j < (numFloats - 1); j++)
	{
		pt = j;
		k = j + 1;
		
	while( k < numFloats)
	{	
		if (x[pt] > x[k])
		{
			pt = k;
			
		}
		
		k = k + 1;
		
	}
	
	temp = x[j];
	x[j] = x[pt];
	x[pt] = temp;
	
	
	}
	printf("\nThe values you entered sorted : \n");
	for (int i = 0; i < numFloats; i++)
	{
		printf("%f\n" , x[i]);
	}
	
	for (int k = 0; k < numFloats; k++)
	{
		sum += x[k];
		
	}
	
	return sum;
	
}	


int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * fact(n-1);
		
}

double sine(float angle) 
{
	float sine = 0;
	float oldSine = sin(angle);
	float rad = angle * (pi / 180);
	
	for(int i = 0; ((fabs(sine - oldSine)) > EPSILON); i++) 
	{
			
		oldSine = sine;
		sine += pow(-1, i) / (fact(2*i + 1)) * pow(rad, 2*i + 1);

	}
	
		return sine;
}
