#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define MAXSIZE 50


int main(int argc, char **argv)
{
	double start, end;
	start = MPI_Wtime();

	double w=0.25;
	int myid, numprocs;
	int data[MAXSIZE], i, x, low, high;
        double myresult[50];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	if(0 == myid) {
		for(i=0; i<MAXSIZE; i++) {
			data[i]=i;
		}
	}
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);
	x = MAXSIZE/numprocs;	/* must be an integer */
	low = myid * x;
	high = low + x;
	for(i=low; i<high; i++) {
		myresult[i] = (data[i] * w)*(2 * (data[i] * w)*(data[i] * w)) + (0.5*(data[i] * w));
		printf("Y ciktimiz: %.2f X DeÄŸeri: %d \t Process: %d\n", myresult[i],data[i],myid);
	}
	end = MPI_Wtime();
	double son=end-start;
	printf("process bitiþ zamani n.%d %f\n\n\n",myid, son);
	MPI_Finalize();





}
