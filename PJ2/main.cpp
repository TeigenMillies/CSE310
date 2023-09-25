#include "merge_sort.h"
#include <iostream>

using namespace std;

// Function to print array. Array is called by reference
void print_array (long long int arr[], int number_of_elements)
{
	for (int index = 0; index < number_of_elements; index++)
		cout << arr[ index ] << " ";
	cout << endl;
}

int main()
{
    // Number of elements in array
    int number_of_elements;
    cin >> number_of_elements;

    // Elements in Array
    long long int arr[ number_of_elements ];
    for (int index = 0; index < number_of_elements; index ++)
        cin >> arr[ index ];

    merge_sort (arr, 0, number_of_elements - 1);
    print_array (arr, number_of_elements);

    return 0;
}
