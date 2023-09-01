// Angelina Toste

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int main (void)
{

    //--Timer--
    double TIMER(void){
    struct timeval tp;
    struct timezone tzp;

        gettimeofday(&tp, &tzp);

        return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6);
    }

    // COMPARING FACTORIAL ALGORITHMS ITERATIVE VS. RECURSIVE
    printf("Factorials iterative and recursive runtimes (in seconds).\n\n");

    //initializing counter upper limit for factorial loops
        int A = 1000;

    //Factorial (iterative)
    double t_0 = TIMER();
    int n;

    //the following for loop will find the factorial of each value in the range of 0 to A.
    for(n = 0; n>=0 && n<=A; n++){
        unsigned int factorial(unsigned int n) {
        unsigned int i, result = 1;
            for(i = 1; i <= n; i++) result *= i;
            return result;
        }
        factorial(n);
    }

    double t_1 = TIMER();


    double total = t_1 - t_0;

    printf("Factorial (iterative): %lf \n", total);



    //Factorial (recursive)
    double t_2 = TIMER();
    int x;
    for(x = 0; x>=0 && x<=A; x++){
        unsigned int factorial(unsigned int x) {
            if (x <= 1) {
        	   return 1; // base case
        	} else {
        	       return x * factorial(x-1); // recursive case
        	}
        }
        factorial(x);

    }

    double t_3 = TIMER();

    double total_2 = t_3 - t_2;

    printf("Factorial (recursive): %lf \n", total_2);



    // COMPARING FIBONACCI ALGORITHMS ITERATIVE VS. RECURSIVE
    printf("\nFibonacci iterative and recursive runtimes (in seconds).\n\n");

    //initializing counter upper limit for fibonacci loops
    int B = 20;

    //Fibonacci (iterative)
    double t_4 = TIMER();
    int N;

    //the following for loop will find the factorial of each value in the range of 0 to B.
    for(N = 0; N>=0 && N<=B; N++){
    	unsigned int fib(unsigned int N) {
    	unsigned int k1, k2, k3;
    	    k1 = k2 = k3 = 1;
    	    for (int j = 3; j <= N; j++) {
    	        k3 = k1 + k2;
    	        k1 = k2;
    	        k2 = k3;
    	    }
    	    return k3;
    	}
    	fib(N);


    }

    double t_5 = TIMER();

    double total_3 = t_5 - t_4;

    printf("Fibonacci (iterative): %lf \n", total_3);


    //Fibonacci (recursive)
    double t_6 = TIMER();
    int X;
    for(X = 0; X>=0 && X<=B; X++){
    	unsigned int fib(unsigned int X) {
    	    if (X <= 1) {
    	        return X;
    	    } else {
    	        return fib(X-1)+fib(X-2);
    	    }
    	}
    	fib(X);
    }

    double t_7 = TIMER();

    double total_4 = t_7 - t_6;

    printf("Fibonacci (recursive): %lf \n", total_4);

    return 0;
}

