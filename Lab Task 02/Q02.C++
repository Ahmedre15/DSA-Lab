#include <iostream>
using namespace std;

int main() {
    int st = 5;
    int sub = 4;
    
    int** marks = new int*[st];
    for (int i = 0; i < st; i++) {
        marks[i] = new int[sub];
    }


    for (int i = 0; i < st; i++) {
        cout << "Enter marks for Student " << i + 1 << ":\n";
        for (int j = 0; j < sub; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
        cout << endl;
    }

    
    int* totalMarks = new int[st];
    for (int i = 0; i < st; i++) {
        totalMarks[i] = 0; 
        for (int j = 0; j < sub; j++) {
            totalMarks[i] += marks[i][j];
        }
    }

    double* avgMarks = new double[sub];
    for (int j = 0; j < sub; j++) {
        int sum = 0;
        for (int i = 0; i < st; i++) {
            sum += marks[i][j];
        }
        avgMarks[j] = sum / st;
    }

    
    int topperIndex = 0;
    for (int i = 1; i < st; i++) {
        if (totalMarks[i] > totalMarks[topperIndex]) {
            topperIndex = i;
        }
    }
    cout << "\nTotal marks of each student:\n";
    for (int i = 0; i < st; i++) {
        cout << "Student " << i + 1 << ": " << totalMarks[i] << endl;
    }

    cout << "\nAverage marks of each subject:\n";
    for (int j = 0; j < sub; j++) {
        cout << "Subject " << j + 1 << ": " << avgMarks[j] << endl;
    }

    cout << "\nTopper student is Student " << topperIndex + 1
         << " with total marks " << totalMarks[topperIndex] << endl;


    return 0;
}