// Angelina Toste

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	// prompts user to input monthly payment
	float P;
	printf ("Enter your monthly payment: ");
	scanf ("%f", &P);
	printf("\n");

	float r = 0.22;
	float B = 5000.0;

	// dislays interest rate (r), initial balance(B), and monthly payment(P)
	printf ("r = %1.2f \n", r);
	printf ("B = %1.1f \n", B);
	printf ("P = %1.1f \n \n", P);

	// initializing counter for months
	int x = 1;

	// initializing variables to track interest and balance for previous months
	float initialInterest = (r/12)*B;
	float previousInterest;
	float previousBalance;

	// initializing accumulator
	float totalInterest = 0.0;

	// loop will finish when B is negative or 0
    while (B >= P)
	{
    	// if statement will execute when it is the first month, x=1
    	if (x == 1)
    	{
    		printf("%d %1.2f %1.2f \n", x, initialInterest, B);

    	    previousInterest = initialInterest;
    	    previousBalance = B;
    	    totalInterest = totalInterest + initialInterest;

    	    x++;

    	}

    	// code will execute for all months except month 1

    	float interestDue = (r / 12 ) * (previousBalance - P + previousInterest);

    	// calculates the new balance after interest has been applied to the previous month's balance
    	B =  previousBalance - (P - previousInterest);

    	printf("%d %1.2f %1.2f \n", x, interestDue, B);
    	previousInterest = interestDue;
    	previousBalance = B;
    	totalInterest = totalInterest + interestDue;

		x++;

	}

    printf("\nTotal interest paid: %1.2f", totalInterest);

	return 0;
}

