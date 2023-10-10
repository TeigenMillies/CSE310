#include <iostream>
#include <string.h>
//#include "heap.h"
#include <vector>


using namespace std;


#define MAX 10000   //max number of queries

void heapifyDown(long int arr[], int size, int element_index) {
    // initialize root and child nodes
    int largest = element_index;
    int left_index  = 2 * element_index + 1;
    int right_index = 2 * element_index + 2;

    //check if left is larger than root
    if (left_index < size && arr[left_index] > arr[largest]) {
        largest = left_index;
    }

    //check right
    if (right_index < size && arr[right_index] > arr[largest])
        largest = right_index;

    //check if largest is not root
    if (largest != element_index) {
        swap(arr[element_index], arr[largest]);
        heapifyDown(arr, size, largest);
    }
}
void heapifyUp(long int heap[], int element_index) {
    int parent = (element_index - 1) / 2;
    while (element_index > 0 && heap[element_index] > heap[parent]) {
        swap(heap[element_index], heap[parent]);
        element_index = parent;
        parent = (element_index - 1) / 2;
    }
}

void insert( long int heap[], int key) {
    heap[10000] = key;
    heapifyUp(heap, 10000);
}

void deleteMax(long int heap[]) {
    //check if empty
    if (heap[0] == 0)
        return;
    //swap head with end, delete end, then fix heap
    else {
        swap(heap[0], heap[10000 - 1]);
        heap[10000 - 1] = 0;
        heapifyDown(heap, 10000, 0);
    }
}

void printMax(long int heap[]) {
    //check if empty
    if (heap[0] != 0) 
        cout << heap[0] << "\n";
    else
        cout << "\n";
}


int main() {
    //get num queries
    int num_queries;
    cin >> num_queries;
    long int heap[10000] = {0};

    //check each command until num_queries
    char commands [20];
    for (int i = 0; i < num_queries; i++) {
        cin >> commands;
        //if insert then get next input as key to insert
        if (strcmp(commands, "INSERT") == 0)
        {
            int key;
            cin >> key;
            insert(heap, key);
        }
        else if(strcmp(commands, "PRINT") == 0)
        {
            printMax(heap);
        }
        else if(strcmp(commands, "DELETE") == 0) 
        {
            deleteMax(heap);
        }
    }
  
}

