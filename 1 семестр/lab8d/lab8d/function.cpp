#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double find_deviation(double MAX_I, double MAX_J, double** mass)
{
	double res = 0;
	for (int i = 0; i < MAX_I; i++)
	{
		double sum = 0;
		for (int j = 0; j < MAX_J; j++)
			sum = sum + mass[i][j];
		double xsr = sum / MAX_J;
		double sumkvad = 0;
		for (int j = 0; j < MAX_J; j++) 
			sumkvad = sumkvad + pow(mass[i][j] - xsr, 2);
		double sigma = sqrt(sumkvad / MAX_J);
		if (sigma > res) 
			res = sigma;
		printf("sigma = %lf \n", sigma);
	}
	for (int i = 0; i < MAX_I; i++)
		free(mass[i]);
	free(mass);
	return res;
}