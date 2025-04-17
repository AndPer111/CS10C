#include <iostream>

#include "IntList.h"

using namespace std;

// default constuctor
// sets dummyHead and tail to each other
IntList::IntList() : dummyHead(new IntNode(0)), dummyTail(new IntNode(0)) {
    dummyHead->next = dummyTail;
    dummyHead->prev = dummyTail;
    dummyTail->next = dummyHead;
    dummyTail->prev = dummyHead;
}

// deletes everything in list
IntList::~IntList() {
    IntNode* curr = dummyHead;

    // while curr isn't dummyTail point next to curr next, delete curr, then point curr to next node till end of list 
    while (curr != dummyTail) {
        IntNode* nextNode = curr->next;

        delete curr;

        curr = nextNode;
    }
}

// adds value to front
// create newNode and point to new IntNode with value
void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    // if empty, head's next is the new node with the value and replaces tail as head's next
    // newNode's next becomes tail
    if (empty()) {
        dummyHead->next = newNode;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
        newNode->prev = dummyHead;
    }
    
    // if it's not empty than head's next (nextNode) becomes newNode and newNode's next becomes nextNode
    else {
        IntNode *nextNode = dummyHead->next;

        dummyHead->next = newNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        newNode->prev = dummyHead;
    }
}

// removes value at front of list
void IntList::pop_front() {
    // curr is head's next and nextNode is curr's next
    IntNode *curr = dummyHead->next;
    IntNode *nextNode = curr->next;
   
   // delete curr and point dummyHead's next is nextNode
    delete curr;

    dummyHead->next = nextNode;
    nextNode->prev = dummyHead;
}

// adds value to back of the list
// set newNode to new IntNode with value
void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);

    // if empty, head's next is newNode in front of tail (new order: dummyHead, newNode, dummyTail)
    if (empty()) {
        dummyHead->next = newNode;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
        newNode->prev = dummyHead;
    }

    // else, previousNode's next is newNode and newNode's next is dummyTail
    else {
        IntNode *previousNode = dummyTail->prev;

        previousNode->next = newNode;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
        newNode->prev = previousNode;
    }
}

// removes value from the back of the list 
void IntList::pop_back() {
    // currNode is before dummyTail and previousNode is currNode's prev
    IntNode *currNode = dummyTail->prev;
    IntNode *previousNode = currNode->prev;

    // delete currNode and point previousNode's next to tail
    delete currNode;
    previousNode->next = dummyTail;
    dummyTail->prev = previousNode;
}

bool IntList::empty() const {
    return dummyHead->next == dummyTail;
}

// overloads output operator to output IntList values
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *currNode = rhs.dummyHead->next;
    
    // if right hand side isn't empty and currNode's next isn't right hand side's dummyTail, output currNode's value and traverse through the list 
    if (!rhs.empty()) {
        while (currNode->next != rhs.dummyTail) {
            out << currNode->data << " ";
            currNode = currNode->next;
        }

        out << currNode->data;
    }

    return out;
}

// reverses list by starting from dummy tail
void IntList::printReverse() const {
    // currNode points to tail's previous
    IntNode *currNode = dummyTail->prev;

    // while loop to reverse the list by outputting dummyTail's prev till it goes to head
    while (currNode != dummyHead) {
        cout << currNode->data << " ";
        currNode = currNode->prev;
    }
}