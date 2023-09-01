// Angelina Toste
/*
 * Assignment 4
 * This assignment will compare the runtimes of:
 * - Bubble Sort
 * - Merge Sort*
 * - Quick Sort
 * - Insertion Sort
 *
 *
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




void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);


    merge(arr, l, m, r);
  }
}


void quicksort(int number[], int first, int last){
	int i, j, pivot, temp;

    if(first < last){
        pivot = first;
        i = first;
        j = last;

        while(i < j){
            while (number[i] <= number[pivot] && i < last)
        	    i++;
        	while (number[j] > number[pivot])
        		j--;
        	if(i<j){
        		temp = number[i];
        		number[i] = number[j];
        		number[j] = temp;
            }

         }

         temp = number[pivot];
         number[pivot] = number[j];
         number[j] = temp;
         quicksort(number, first, j-1);
         quicksort(number, j+1, last);

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


#define size 16

int main() {
	//Initializing array of defined size N
    int data[size];

	// BUBBLE SORT ALGORITHM
	    printf("Bubble Sort Runtime (in seconds).\n");

	    //initializing counter upper limit for bubble sort loops
	    int A = 500000000;


	    //populate array for bubble sort
	    for (int i = 0; i < size; i++)
	    	data[i] = rand()%65536;

	    //Bubble Sort
	    printf("start\n");
	    double t_0 = TIMER();
	    int n;

	    for(n = 1; n>=0 && n<=A; n++){

	        bubbleSort(data, size);

	    }

	    double t_1 = TIMER();

	    double total = t_1 - t_0;

	    printf("Bubble Sort: %lf \n\n", total);

	//MERGE SORT ALGORITHM
	    printf("Merge Sort Runtime (in seconds).\n");

	    double t_6 = TIMER();


	    //the following for loop will run the quick sort n amount of times.

	    for (n = 1; n>=0 && n<=A; n++){

	        mergeSort(data, 0, size - 1);

	    }

	    double t_7 = TIMER();
	    double total_4 = t_7 - t_6;


	    printf("Merge Sort: %lf \n\n", total_4);


	//QUICK SORT ALGORITHM
	    printf("Quick Sort Runtime (in seconds).\n");
	    double t_4 = TIMER();


	    //the following for loop will run the quick sort n amount of times.
	    for (n = 1; n>=0 && n<=A; n++){

	    	 quicksort(data, 0, size - 1);

	    }

	    double t_5 = TIMER();

	    double total_3 = t_5 - t_4;

	    printf("Quick Sort: %lf \n\n", total_3);


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


}



