#include "minheap.h"


MinHeap::MinHeap() {
    //set pointers to nullptr
    //set variables to default values
    keys = nullptr;
    values = nullptr;
    capacity = 0;
    size = 0;
}

void MinHeap::init(int size) {
    //set capacity and size
    //allocate memory for keys(weights) and values(nodes)
    capacity = size;
    keys = new double[size];
    values = new int[size];
}

void MinHeap::push(double key, int value) {
    /*
    if heap is full
        return

    increase size
    set key and value at the end with index as size
    heapify up
    */
    if (size == capacity) 
        return;

    size++;
    keys[size - 1] = key;
    values[size - 1] = value;
    heapifyUp(size);            //inputs size in 0-index. GIVES THE VALUE IN THE ARRAY
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
    int root = values[0];
    values[0] = values[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

bool MinHeap::empty() const {
    //return true if size is 0, false otherwise
    return size == 0;
}

void MinHeap::heapifyUp(int index) {
    /*
    while index > 1 and current key is less than parent key (parent key is index / 2)
        swap index with parent
        update index to parent
    */
   while (index > 1 && keys[index] < keys[index/2]) {       //CHECK IF WRONG
    swap(index, index/2);
    index = index/2;
   }
}

void MinHeap::heapifyDown(int index) {
    /*
    find the smallest child from left(2*index) or right(2*index+1) child of index
    if smallest child is smaller than current key
        swap with smallest child with index
        update index
        heapify down
    */
    int sIndex = 2 * index;
    int smallest = keys[sIndex];
    if (smallest > keys[sIndex + 1]) {
        smallest = keys[2 * index + 1];
        sIndex++;
    }
        

    if(smallest < keys[index]) {
        swap(sIndex, index);
        index++;
        heapifyDown(index);
    }
}

void MinHeap::swap(int i, int j) {
    //swap keys and values at positions i and j
    double temp = keys[i];
    keys[i] = keys[j];
    keys[j] = temp;

    int temp1 = values[i];
    values[i] = values[j];
    values[j] = temp1;
}
