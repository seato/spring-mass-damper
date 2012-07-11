#include <stdio.h>
#include "main.h"

void init(FILE * inFile, double * m, double * k, double * c, double * t_stop, double * dt, double * t, double x[]);
void force(double * f, double * m, double x[]);
void plant(double * f, double * m, double * c, double * k, double x[]);
void numerical(double * DT, double x[]);

int main()
{
	double m, k, c, t_stop, dt, t, f, x[3];
	double * m_ptr = &m;
	double * k_ptr = &k;
	double * c_ptr = &c;
	double * t_stop_ptr = &t_stop;
	double * dt_ptr = &dt;
	double * t_ptr = &t;
	double * f_ptr = &f;
	FILE * inFile;
	FILE * outFile;
	init(inFile, m_ptr, k_ptr, c_ptr, t_stop_ptr, dt_ptr, t_ptr, x);
	outFile = fopen("output.txt", "w");

	while(t < t_stop)
	{
		force(f_ptr, m_ptr, x);
		plant(f_ptr, m_ptr, c_ptr, k_ptr, x);
		fprintf(outFile, "%.1lf,%.1lf,%.1lf,%.1lf,%.1lf\n", t, f, x[0], x[1], x[2]);
		numerical(dt_ptr, x);
		t += dt;
	}

	fclose(outFile);

	return 0;
}
