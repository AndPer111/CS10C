#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class stack {
    private: 
    // const called MAX_SIZE storing the value of 20
    static const int MAX_SIZE = 20;
    // private data fields
    T data[MAX_SIZE];
    int size;

    public:
    // constructing empty stack
    stack() {
        size = 0;
    }

    void push(T val) {
        // if size is greater than or equal to MAX_SIZE, throw an overflow error
        if (size >= MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }

        // if not then size is increment by 1 and data's size is equal to val in parameter
        data[size] = val;
        ++size;
    }

    void pop() {
        // if empty, throw out of range error
        if (empty()) {
            throw out_of_range("Called pop on empty stack.");
        }
        
        // if not then decrement size by 1
        --size;
    }

    void pop_two() {
        // if empty or size equals 1, throw out of range
        if (empty() || size == 1) {
            
            // if empty, throw out of range with this statment
            if (empty()) {
                throw out_of_range("Called pop_two on empty stack.");
            }

            // if size equals 1, throw out of range with this statment
            if (size == 1) {
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
        }

        // if those conditions don't apply, subtract two from size
        size -= 2;
    }

    T top() {
        // if empty, throw underflow error
        if (empty()) {
            throw underflow_error("Called top on empty stack.");
        }

        // else, return last element on stack by subtracing size by 1 and entering it in data array
        return data[size-1];
    }

    bool empty() {
        // true if size is 0
        return size == 0;
    }

};