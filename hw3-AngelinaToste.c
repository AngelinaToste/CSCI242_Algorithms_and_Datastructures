// Angelina Toste
/*
 * Assignment 3
 * This assignment will compare the runtimes of:
 * - Bubble Sort
 * - Insertion Sort
 * - Quick Sort
 *
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


void bubbleSort(int array[], int size) {

	  for (int step = 0; step < size - 1; ++step) {

	    for (int i = 0; i < size - step - 1; ++i) {

	      if (array[i] > array[i + 1]) {

	        int temp = array[i];
	        array[i] = array[i + 1];
	        array[i + 1] = temp;
	      }
	    }
	  }
	}


void insertionSort(int arr[], int n){
            int i, key, j;
            for (i = 1; i < n; i++){
                key = arr[i];
                j = i - 1;

                while( j >= 0 && arr[j] > key){
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
}

void quicksort(int number[25], int first, int last){
	int i, j, pivot, temp;

    if(first < last){
        pivot = first;
        i = first;
        j = last;

        while(i < j){
            while (number[i] <= number[pivot] && i < last)
        	    i++;
        		while (number[j] > number[pivot]){
        			j--;
        			if(i<j){
        				temp = number[i];
        				number[i] = number[j];
        				number[j] = temp;
        		    }
        		}
         }

         temp = number[pivot];
         number[pivot] = number[j];
         number[j] = temp;
         quicksort(number, first, j-1);
         quicksort(number, j+1, last);

    }
}


int main() {
	//Initializing array for the sorting algorithms
    int data[] = {-2, 45, 0, 11, -9};

    // length of the array
	int size = sizeof(data) / sizeof(data[0]);

	// BUBBLE SORT ALGORITHM
	    printf("Bubble Sort Runtime (in seconds).\n");

	    //initializing counter upper limit for bubble sort loops
	    int A = 10000;

	    //Bubble Sort
	    double t_0 = TIMER();
	    int n;

	    for(n = 1; n>=0 && n<=A; n++){

	        bubbleSort(data, size);

	    }

	    double t_1 = TIMER();

	    double total = t_1 - t_0;

	    printf("Bubble Sort: %lf \n\n", total);

	 // INSERTION SORT ALGORITHM
	    printf("Insertion Sort Runtime (in seconds).\n");


	    double t_2 = TIMER();

	    //the following for loop will run the insertion sort n amount of times.
	    for(n = 1; n>=0 && n<=A; n++){

	    	insertionSort(data, size);

	    }
	    double t_3 = TIMER();

	    double total_2 = t_3 - t_2;

	    printf("Insertion Sort: %lf \n\n", total_2);

	//QUICK SORT ALGORITHM
	    printf("Quick Sort Runtime (in seconds).\n");
	    double t_4 = TIMER();


	    //the following for loop will run the quick sort n amount of times.

	    for (n = 1; n>=0 && n<=A; n++){

	    	quicksort(data, 0, size - 1);

	    }

	    double t_5 = TIMER();

	    double total_3 = t_5 - t_4;

	    printf("Quick Sort: %lf \n", total_3);


}
