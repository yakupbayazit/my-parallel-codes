 
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
    auto start = std::chrono::system_clock::now(); 
	double x[50];  //deðiþkenler
	double y[50];
	double w=0.25;

	for (int i=0;i<50;i++) 
	{
		x[i]=i;
	}

	for(int i=0;i<50;i++)
	{
	  
	   y[i]=(x[i]*w)*(2*(x[i]*w)*(x[i]*w))+(0.5*(x[i]*w));  
	   	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = end - start;
		cout<<i<<"\t x girdimiz:\t"<<x[i]<<"\t y çýktýmýz\t"<<y[i]<<"\t"<< "zaman: " << elapsed.count() << " s\n";
	}
}