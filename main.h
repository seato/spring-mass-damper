#ifndef _MAIN_H
#define _MAIN_H

void init(FILE * inFile, double * m, double * k, double * c, double * t_stop, double * dt, double * t, double x[]);
void force(double * f, double * m, double x[]);
void plant(double * f, double * m, double * c, double * k, double x[]);
void numerical(double * DT, double x[]);

#endif
