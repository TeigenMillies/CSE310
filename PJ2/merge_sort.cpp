#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) 
{
    // Sub-array sizes
	int const sub_array_one = 
	int const sub_array_two = 

	// Create temp arrays
	long long int *left_array = 
	long long int *right_array = 

	/* Copy data to temp arrays leftArray[] and rightArray[] */
        // Your code here


    /* Indices of the left, right and merged array*/
        // Your code here


	/* Merge the temp arrays back into array[left..right] */
        // Your code here


	/* Copy the remaining elements of
	   left[], if there are any */
        // Your code here


	/* Copy the remaining elements of
	   right[], if there are any */
       // Your code here


	// Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end)
{
    /* Recursive calls of merge_sort and merge_two_sorted_arrays */
        // Your code here

	
}
