// test_standards_violations.cpp
// This file contains intentional violations to test code review tools

#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>

using namespace std;  // Violation: Google Style forbids using namespace std in header files

#define MAX_SIZE 100  // Violation: AUTOSAR/MISRA prefer constexpr over macros

int global_var = 0;  // Violation: Global variables are discouraged

// Violation: Missing documentation comment
class TestClass {
private:
    int* ptr;
    int size;

public:
    // Violation: Raw pointer ownership unclear
    TestClass(int s) : size(s) {
        ptr = new int[s];  // Violation: MISRA/AUTOSAR discourage dynamic memory
    }
    
    // Violation: Missing copy constructor and assignment operator (rule of three)
    
    ~TestClass() {
        delete[] ptr;  // Violation: Should use delete[] if new[] was used
    }
    
    // Violation: Inconsistent naming style
    void set_value(int index, int value) {
        if (index < size) {  // Violation: No bounds checking
            ptr[index] = value;
        }
    }
    
    int getValue(int index) {  // Violation: Inconsistent naming
        return ptr[index];  // Violation: No bounds checking
    }
};

// Violation: Function with too many parameters
void process_data(int a, int b, int c, int d, int e, int f, int g) {
    // Violation: Magic numbers
    if (a > 10) {
        cout << "Value is large" << endl;
    }
    
    // Violation: Potentially unused variable
    int temp = a + b;
    
    // Violation: C-style cast
    double result = (double)a / b;
}



// Violation: Function with high complexity
void complex_function(int x) {
    switch(x) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
        case 10:
            cout << "Ten";
            break;
        default:
            cout << "Many";
            break;
    }
}

// Violation: Inline assembly not allowed in safety-critical code
void assembly_function() {
    asm("nop");  // Violation: Inline assembly
}

// Violation: Recursion discouraged in safety-critical code
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Violation: Exception handling not allowed in AUTOSAR
void exception_function() {
    try {
        throw runtime_error("test");  // Violation: Exceptions not allowed
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

// Violation: Static and thread_local variables discouraged
void static_function() {
    static int counter = 0;  // Violation: Static variable
    counter++;
}

// Violation: Function with side effects
int& get_global() {
    return global_var;  // Violation: Returning reference to global
}

int main() {
    // Violation: C-style array
    int arr[10];
    
    // Violation: C-style memory management
    int* dynamic_arr = (int*)malloc(10 * sizeof(int));  // Violation: malloc in C++
    
    // Violation: Potential buffer overflow
    for (int i = 0; i <= 10; i++) {
        arr[i] = i;  // Violation: Off-by-one error
    }
    
    // Violation: Uninitialized variable
    int uninitialized;
    cout << uninitialized << endl;
    
    // Violation: Type punning
    float f = 1.0f;
    int& i = reinterpret_cast<int&>(f);  // Violation: Type punning
    
    TestClass obj(5);
    obj.set_value(10, 100);  // Violation: Out of bounds access
    
    complex_function(15);
    assembly_function();
    fibonacci(10);
    exception_function();
    static_function();
    
    get_global() = 5;  // Violation: Modifying global through reference
    
    // Violation: Memory leak (dynamic_arr not freed)
    return 0;
}
