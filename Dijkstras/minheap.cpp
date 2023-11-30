#include <iostream>
#include <string.h>
#include "minheap.h"
//#include "heap.h"
//#include <vector>


using namespace std;


#define MAX 10000   //max number of queries

MinHeap::MinHeap() {
    //set pointers to nullptr
    //set variables to default values
}

bool MinHeap::empty() const {
    //return true if size is 0, false otherwise
    return size == 0;
}

int MinHeap::pop() {
    /*
    if heap is empty
        return sentinel value

    get root value
    replace root with the last element
    decrease size
    heapify down

    return root value
    */
    if (empty()) {
        return -1;
   }

}

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