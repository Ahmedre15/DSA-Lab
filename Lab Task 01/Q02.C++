#include <iostream>   // header file for input/output
using namespace std;  // standard namespace

class Exam {
    string* name;      // pointer for student name
    int score;         // exam score
    string* examdate;  // pointer for exam date

public:
    // Constructor with DMA
    // here we allocate dynamic memory for strings
    Exam(const char* n, int s, const char* ED) {
        name = new string(n);        // store name dynamically
        score = s;                   // set score
        examdate = new string(ED);   // store exam date dynamically
    }

    // Destructor
    // used to free memory allocated by new
    ~Exam() {
        delete name;     
        delete examdate; 
        cout << "Destructor called" << endl; 
    }

    // Method to update exam details
    void setDetails(const char* n, int s, const char* ED) {
        *name = n;          // update name
        score = s;          // update score
        *examdate = ED;     // update exam date
    }

    // Method to display student exam details
    void display() {
        cout << "Student: " << *name
             << ", Score: " << score
             << ", Exam Date: " << *examdate << endl;
    }

};

int main() {
    Exam exam1("Affan", 90, "2025-08-24");
    exam1.display();   // show details of exam1

    // here a new object exam2 is created as a copy of exam1
    // default shallow copy is used (pointer addresses copied, not data)
    Exam exam2 = exam1;
    exam2.display();   // initially shows same values as exam1

    cout << "\nChanging exam2 details...\n";
    // update exam2 details
    exam2.setDetails("Ahmed", 75, "2025-09-01");

    // because of shallow copy, changes in exam2 affect exam1 also
    cout << "Exam1 (affected due to shallow copy):\n";
    exam1.display();  

    // display exam2 normally
    cout << "Exam2:\n";
    exam2.display();

    return 0;   //returning 0
}