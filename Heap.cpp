// implementing Heap functions 
#include "Heap.h"

#include <iostream>

using namespace std;

// constructor
Heap::Heap() : numItems(0) {
}

void Heap::enqueue(PrintJob* job) {
    // if numItems does not equal max heap size declared in private and numItems is 0 then set array with numItems in it to job and increment numItems
    if (numItems != MAX_HEAP_SIZE) {

        if (numItems == 0) {
            arr[numItems] = job;
            ++numItems;
        }

        // else set numItems to index
        else {
            int index = numItems;

            // while the index (numItems) is greater than 0 and array's priority is greater than job's, set array with index to arr with index - 1 divided by 2 and do the same to index
            // while loop to make sure arr[(index - 1)/2] is a child of job and also lower in priority
            while (index > 0 && arr[(index - 1) / 2]->getPriority() < job->getPriority()) {
                arr[index] = arr[(index - 1) / 2];
                index = (index - 1) / 2;
            }

            // result of loop that get index set to job, increment numItems by 1
            arr[index] = job;
            ++numItems;
        }
    }
}

void Heap::dequeue() {
    // if numItems is 0 there is nothing to dequeue
    if (numItems == 0) {
        cout << "Cannot dequeue empty heap." << endl;
        return;
    }

    // if it is greater than 0 and not equal to 1 set the first element of the array to the root
    if (numItems > 0) {

        if (numItems != 1) {
            arr[0] = arr[numItems - 1];
        }
        
        // decrement numItems and call trickle down with 0 as the parameter
        --numItems;
        trickleDown(0);
    }
}

PrintJob* Heap::highest() {
    // if numItems is 0 then return null 
    if (numItems == 0) {
        return nullptr;
    }

    // highest returns array's first element (root)
    return arr[0];
}

void Heap::print() {
    // if numItems is 0 there is nothing to print
    if (numItems == 0) {
        cout << "Heap is empty." << endl;
    }

    else {
        // else output highest priority by calling highest and pointing it to priority, getJobNumber, and getPages (gets the highest value for all these functions)
        cout << "Priority: " << highest()->getPriority();
        cout << ", Job Number: " << highest()->getJobNumber();
        cout << ", Number of Pages: " << highest()->getPages() << endl;
    }
}

// recursive function helper for dequeue
void Heap::trickleDown(int index) {
    // means there is no children, base case
	if (numItems < index * 2 + 2) {
        return;
    }

    // for 1 child
    else if (numItems == index * 2 + 2) {
        
        // if array at index's priority is less than the root's then swap
        if (arr[index]->getPriority() < arr[numItems - 1]->getPriority()) {
            swap(index, numItems - 1);
        }
    }

    // for 2 children
    else {
        // this declaration for left and right child (l for left r for right)
        PrintJob* lChild = arr[index * 2 + 1];
        PrintJob* rChild = arr[index * 2 + 2];

        // if left child's priority is greater, compare to index 
        if (lChild->getPriority() > rChild->getPriority()) {
            
            // if index array at index's priority is less than array at the left child, swap
            if (arr[index]->getPriority() < arr[index * 2 + 1]->getPriority()) {
                swap(index, index * 2 + 1);
            }

            // calls trickle down at left child
            trickleDown(index * 2 + 1);
        }

        else {
            
            // else, if array at index's priority is less than the array at the right child, swap
            if (arr[index]->getPriority() < arr[index * 2 + 2]->getPriority()) {
                swap(index, index * 2 + 2);
            }

            // call trickle down at right child
            trickleDown(index * 2 + 2);
        }
    }
}

// helper for trickle down (to swap values)
void Heap::swap(int firstNum, int secondNum) {
    // create PrintJob swap and set to array with the firstNum and swap with secondNum 
	PrintJob* swap = arr[firstNum];
	arr[firstNum] = arr[secondNum];
	arr[secondNum] = swap;
}