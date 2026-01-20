#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    //  Create a jagged array for departments
    int*** marks = new int**[departments];  // 3D: dep  students  subjects
    int* students = new int[departments];  

    //Input student counts and marks
    for (int d = 0; d < departments; d++) {
        cout << "\nEnter number of students in department " << d + 1 << ": ";
        cin >> students[d];

        // Allocate memory for students in this department
        marks[d] = new int*[students[d]];

        // Each student has marks in 5 subjects
        for (int s = 0; s < students[d]; s++) {
            marks[d][s] = new int[5];
            cout << "Enter 5 subject marks for student " << s + 1 << " of Dept " << d + 1 << ": ";
            for (int subj = 0; subj < 5; subj++) {
                cin >> marks[d][s][subj];
            }
        }
    }

    //  Calculate highest, lowest, and average for each department
    cout << fixed << setprecision(2);
    for (int d = 0; d < departments; d++) {
        int highest = -1e9, lowest = 1e9;
        double sum = 0;
        int totalMarks = students[d] * 5;

        for (int s = 0; s < students[d]; s++) {
            for (int subj = 0; subj < 5; subj++) {
                int m = marks[d][s][subj];
                if (m > highest) highest = m;
                if (m < lowest) lowest = m;
                sum += m;
            }
        }

        double avg = (totalMarks > 0) ? (sum / totalMarks) : 0;

        cout << "\nDepartment " << d + 1 << " Results:\n";
        cout << "Highest Mark: " << highest << endl;
        cout << "Lowest Mark: " << lowest << endl;
        cout << "Average Marks: " << avg << endl;
    }

    // Step 4: Deallocate memory
    for (int d = 0; d < departments; d++) {
        for (int s = 0; s < students[d]; s++) {
            delete[] marks[d][s];
        }
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;

    return 0;
}
