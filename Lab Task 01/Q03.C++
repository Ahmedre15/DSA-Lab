#include <iostream>   // header file for input/output
using namespace std;

class Box {
    int* data;   // pointer to an integer (using DMA)

public:
    // Constructor
    Box(int value) {
        data = new int(value);   // allocate memory for integer and store value
        cout << "Constructor called, value = " << *data << endl;
    }

    // Destructor
    ~Box() {
        // free memory to avoid memory leak
        cout << "Destructor called, deleting data = " << *data << endl;
        delete data;
    }

    // Copy Constructor (Deep Copy)
    Box(const Box& other) {
        // allocate new memory and copy the value from other object
        data = new int(*other.data);
        cout << "Copy Constructor called, copied value = " << *data << endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Box& operator=(const Box& other) {
        // check for self-assignment (object = object)
        if (this != &other) {
            delete data;                 // delete old memory
            data = new int(*other.data); // allocate new memory and copy value
        }
        cout << "Copy Assignment Operator called, value = " << *data << endl;
        return *this;  // return current object
    }

    // Function to change the stored value
    void setValue(int value) {
        *data = value;
    }
     
    void display() const {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    cout << "=== Creating box1 ===" << endl;
    Box box1(10);   // constructor will run
    box1.display(); 

    cout << "\n=== Creating box2 using Copy Constructor (Deep Copy) ===" << endl;
    Box box2 = box1;   // copy constructor will run
    box2.display();    // should have the same value as box1 initially

    cout << "\nChanging box2 value to 20..." << endl;
    box2.setValue(20); // only box2 should change
    cout << "Box1 after box2 modified: ";
    box1.display();   // box1 remains unchanged (deep copy)
    cout << "Box2: ";
    box2.display();   // box2 updated

    cout << "\n=== Using Copy Assignment Operator ===" << endl;
    Box box3(30);     // create a new object with value 30
    box3 = box1;      // assignment operator runs (deep copy)
    box3.display();   // now box3 has same value as box1

    cout << "\nChanging box3 value to 50..." << endl;
    box3.setValue(50);  // only box3 changes
    cout << "Box1 after box3 modified: ";
    box1.display();    // box1 remains same
    cout << "Box3: ";
    box3.display();    // box3 updated

    return 0;  
}
