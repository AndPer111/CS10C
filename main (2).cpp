#include <iostream>

#include "IntList.h"

using namespace std;

int main() {
    // create new IntList called testList
    IntList *testList = new IntList();

    // testing push front (list becomes 30,20,10,5))
    cout << "Push front" << endl;
    testList->push_front(5);
    testList->push_front(10);
    testList->push_front(20);
    testList->push_front(30);
   
    // output list
    cout << *testList << endl;

    // test push back (list becomes 30,20,10,5,1,2,3,4)
    cout << "Push back values" << endl;
    testList->push_back(1);
    testList->push_back(2);
    testList->push_back(3);
    testList->push_back(4);

    // reverse list (list becomes 4,3,2,1,5,10,20,30)
    cout << "Reversed list: ";
    testList->printReverse();
    cout << endl;

    // testing pop front 
    cout << "Pop front test" << endl;
    testList->pop_front();
    testList->pop_front();
    testList->pop_front();
    testList->pop_front();

    // output list
    cout << *testList << endl;

    // test pop back function 
    cout << "Pop back test" << endl;
    testList->pop_back();
    testList->pop_back();
    testList->pop_back();
    testList->pop_back();

    // output list
    cout << *testList << endl;

    // test empty function
    cout << "Test if empty" << endl;
    if (testList->empty()) {
        cout << "List is empty." << endl;
    }

    else {
        cout << "The list is not empty yet." << endl;
    }

    // delete testList
    cout << "Test destructor" << endl;
    delete testList;

    return 0;
}