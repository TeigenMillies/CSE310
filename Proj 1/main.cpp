#include <iostream>
using namespace std;

void bubblesort(int arr[], int length)
{
    int index1, index2;
    
    //Go through each element in array
    for (index1 = 0; index1 < length ; index1++)
    {
        for (index2 = 0; index2 < length - index1; index2++)
        {
            //swap bigger elements to the right
            if (arr[index2] > arr[index2 + 1])
            {
                
                int temp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = temp;
                
            }
        }
        
    }
}

void printSort(int arr[], int length)
{
    int index;
    //print each index of array
    for (index = 0; index < length; index++)
        cout << arr[index] << " ";

}

int main()
{
    int length;
    cin >> length;

    int unsorted [length];

    for (int index = 0; index < length; index++)
        cin >> unsorted[index];

    bubblesort(unsorted, length);
    printSort(unsorted, length);
}