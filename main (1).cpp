#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// function declarations

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

template <typename T>
void selection_sort(vector<T> &vals);

template <typename T>
T getElement(vector<T> &vals, int index);

vector<char> createVector();

int main() {
    // integer vector test
    vector<int> intVect = {10, 30, 50, 70, 90, 1, 45, 40, 80, 100};

    // initial values in a list
    cout << "Integer list: ";

    for (int i = 0; i < 10; ++i) {
        cout << intVect.at(i) << " ";
    }
    
    cout << endl;

    // test selection sort (includes min_index function in it)
    selection_sort(intVect);

    // output sorted vector
    cout << "New List: ";
    for (int i = 0; i < 10; ++i) {
        cout << intVect.at(i) << " ";
    }
    cout << endl;

    // testing double vector
    vector<double> doubleVect = {10.50, 30.33, 50.68, 70.99, 90.23, 1.4, 45.66, 40.82, 80.83, 100.7};

    // initial values in a list
    cout << "Double list: ";

    for (int i = 0; i < 10; ++i) {
        cout << doubleVect.at(i) << " ";
    }
    
    cout << endl;

    // test selection sort 
    selection_sort(doubleVect);

    // output sorted vector
    cout << "New Double List: ";
    for (int i = 0; i < 10; ++i) {
        cout << doubleVect.at(i) << " ";
    }
    cout << endl;

    // testing string vector
    vector<string> stringVect = {"The", "And", "Thomas", "Steven", "Mark", "John", "Devin", "Denzel", "Tom", "Patrick"};
    
    // output initial string
    cout << "String List: ";
    for (int i = 0; i < 10; ++i) {
        cout << stringVect.at(i) << " ";
    }
    
    cout << endl;

    // test selection sort for string
    selection_sort(stringVect);

    // output new list
    cout << "New String List: "; 

    for (int i = 0; i < 10; ++i) {
        cout << stringVect.at(i) << " ";
    }

    cout << endl;

    // test for char
    vector<char> charVect = {"A", "E", "I", "U", "O", "Z", "Q", "L", "P", "T"}
    
    // output initial string
    cout << "Char List: ";
    for (int i = 0; i < 10; ++i) {
        cout << charVect.at(i) << " ";
    }
    
    cout << endl;

    // test selection sort for string
    selection_sort(charVect);

    // output new list
    cout << "New Char List: "; 

    for (int i = 0; i < 10; ++i) {
        cout << charVect.at(i) << " ";
    }

    cout << endl;

    
    //Part B
    try {
        srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        int index;
        int numOfRuns = 10;

        while(--numOfRuns >= 0) {
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch (out_of_range& excpt) {
        cout << excpt.what() << endl;
        cout << "Out of range" << endl;
    }

    return 0;
}

// function implementations
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned minVal = index;
    // for loop to get the min val using index
    for (unsigned int i = index; i < vals.size(); ++i) {

        if (vals.at(i) < vals.at(minVal)) {
            minVal = i;
        }
    }

    return minVal;
}

template <typename T>
void selection_sort(vector<T> &vals) {
    // sort list using for loop by getting the minIndex and swapping it till the list is switched to smallest to largest
    for (unsigned int i = 0; i < vals.size(); ++i) {
        unsigned minIndex = min_index(vals, i);
        T value = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = value;
    }
}

// getter to get the value at specific index
template <typename T>
T getElement(vector<T> &vals, int index) {
    // Compare size to unsigned int or else get warning
    unsigned compIndex = index;
    if (index < 0 || compIndex >= vals.size()) {
        throw out_of_range("out of range exception occured");
    }

    return vals.at(index);
}

// given function
vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    
    for(int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
   
    return vals;
}

