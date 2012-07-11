#include "stdafx.h"
#include "init.cpp"

int main(void)
{
	initialize();
// input
	/*
	 * in: 
	 * return: m, k, c, t_stop, dt
	 */
	FILE * inFile;
	double m, k, c, t_stop, dt;
	inFile = fopen("input.txt", "r");
	fscanf(inFile, "%lf,%lf,%lf,%lf,%lf", &m, &k, &c, &t_stop, &dt);
	fclose(inFile);

//init
	/*
	 * in:
	 * return: outFile, time, x, x', x''
	 */
	FILE * outFile;
	float t;
	float x[3];

	x[0] = 0.0; // x
	x[1] = 0.0; // x'
	x[2] = 0.0; // x''
	t = 0.0; // initial time value

	outFile= fopen("output.txt", "w");

	while (t < t_stop)
	{
		//force
		/*
		 * in: m, x
		 * return: f
		 */
			double f = m * x[0]; // force

		// plant
		/*
		 * in: f, m, c, k, x'
		 * return: x''
		 */
			x[2] = f/m - c*x[1]/m - k*x[0]/m;

		//output
		/*
		 * in: outFile
		 * return:
		 */
			fprintf(outFile, "%.1lf,%.1lf,%.1lf,%.1lf,%.1lf\n", t, f, x[0], x[1], x[2]);

		//numerical int
		/*
		 * in:
		 * return:
		 */
			x[0] = x[1]*dt + x[0];
			x[1] = x[2]*dt + x[1];

		// t increment
		/*
		 * in:
		 * return:
		 */
			t += dt;
	}

	fclose(outFile);

	return 0;
}

