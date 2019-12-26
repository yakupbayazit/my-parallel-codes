#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

void func()
{
	double x[50];
	double y[50];
	double w = 0.25;
	double s = 0;
	double now = omp_get_wtime();


	for (int i = 0; i < 50; i++)
	{
		x[i] = i;
	}

#pragma omp parallel for num_threads(nThreads) reduction(+: s)
	for (int i = 0; i < 150; i++)
	{

		y[i] = (x[i] * w)*(2 * (x[i] * w)*(x[i] * w)) + (0.5*(x[i] * w));
		cout << i << "\t x girdimiz:\t" << x[i] << "\t y ciktimiz:\t" << y[i] << "\t"<<"speedup:" <<"\t"<< omp_get_wtime() - now << endl;
	}
	cout <<"toplam gecen zaman"<< omp_get_wtime() - now;
}

int main()
{
	func();
	system("Pause");
	return 0;
}

