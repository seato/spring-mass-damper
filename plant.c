#include <stdio.h>
#include "main.h"

void plant(double * f, double * m, double * c, double * k, double x[])
{
	x[2] = (*f)/(*m) - (*c)*x[1]/(*m) - (*k)*x[0]/(*m);
}
