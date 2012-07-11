#include <stdio.h>
#include "main.h"

void init(FILE * inFile, double * m, double * k, double * c, double * t_stop, double * dt, double * t, double x[])
{
	inFile = fopen("input.txt", "r");
	fscanf(inFile, "%lf,%lf,%lf,%lf,%lf", m, k, c, t_stop, dt);
	fclose(inFile);
	*t = 0.0; // initial time value
	x[0] = 0.0; // x
	x[1] = 0.0; // x'
	x[2] = 0.0; // x''
}
