//Angelina Toste
/*
 * Homewwork 8: Analyzing Fibonacci Algorithms
 *   -Recursive Fibonacci
 *   -Bottom-up Fibonacci
 *   -Top-down Fibonacci
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

//--Timer--
double TIMER(void){
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp, &tzp);

    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6);
}

unsigned int fib(unsigned int n){
	if (n <= 1)
	{
		return n;
	} else{
		return fib(n-1)+fib(n-2);
	}
}

unsigned int fibBU(unsigned int n){
	unsigned int fibBU[100];
	fibBU[0]=0;
	fibBU[1]=1;
	for (int i = 1; i<=n; i++)
	{
		fibBU[i] = fibBU[i-1] + fibBU[i-2];
	}
	return fibBU[n];
}

#define size 100
unsigned int map[size];

unsigned int fibTD(unsigned int n){
    if (map[n] != -1) return map[n];
    map[n] = fibTD(n-1) + fibTD(n-2);
    return map[n];
}

int main(){

	// Recursive Fibonacci

	// initializing upper bound for for loop
	int B = 16;

	double t_0 = TIMER();
	int X;
	for(X = 0; X>=0 && X<=B; X++){
	    fib(X);
	}

	double t_1 = TIMER();

	double total_0 = t_1 - t_0;

	printf("Recursive time: %lf \n", total_0);

	// Dynamic Bottom-up Fibonacci

    // initializing upper bound for for loop
	int A = 100;

	double t_2 = TIMER();

	for(int X = 0; X>=0 && X<=A; X++){
		fibBU(X);
	}

	double t_3 = TIMER();

	double total_1 = t_3 - t_2;

	printf("Bottom-up Time: %lf \n", total_1);

	// Dynamic Bottom-up Fibonacci

	// initializing upper bound for for loop
    int C = 100;

	double t_4 = TIMER();

	for(int X = 0; X>=0 && X<=C; X++){
		for(int j = 2; j < size; j++) map[j] = -1;
		map[0] = 0;
		map[1] = 1;

		fibTD(X);
	}

	double t_5 = TIMER();

	double total_2 = t_5 - t_4;

	printf("Top-down Time: %lf \n", total_2);

}
