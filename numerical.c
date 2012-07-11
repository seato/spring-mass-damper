#include <stdio.h>
#include "main.h"

void numerical(double * dt, double x[])
{
	x[0] = x[1]*(*dt) + x[0];
	x[1] = x[2]*(*dt) + x[1];
}
