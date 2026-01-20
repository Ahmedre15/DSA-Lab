#include <iostream>
using namespace std;


class DynamicMatrix {
private:
    int** matrix;   // Pointer to hold the 2D matrix
    int rows, cols; // Number of rows and columns in the matrix

public:
 
    DynamicMatrix(int r, int c) {
        rows = r;
        cols = c;

        // Allocate memory for rows
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols]; // Allocate memory for each column
        }

        // Take input from the user for each cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value at [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    // Function to resize the matrix
    void resize(int newRows, int newCols) {
        // Create a new matrix with updated size
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newMatrix[i] = new int[newCols];
        }

        // Copy old values if within bounds, otherwise fill with initVal
        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = 0;
                }
            }
        }

        // Free old memory and update pointer
        deallocate();
        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    // Function to transpose the matrix (swap rows and cols)
    void transpose() {
        // Create new matrix with swapped dimensions
        int** newMatrix = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newMatrix[i] = new int[rows];
        }

        // Copy values by swapping indices
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                newMatrix[j][i] = matrix[i][j];
            }
        }

        // Free old memory and update values
        deallocate();
        matrix = newMatrix;

        // Swap row and column values
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    // Function to add 2 to elements at odd indices
    void addTwoToOddIndices() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Check if sum of indices is odd
                if ((i + j) % 2 != 0) {
                    matrix[i][j] += 2;
                }
            }
        }
    }

    // Function to print the matrix
    void print() {
        cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to free allocated memory
    void deallocate() {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
    }

    // Destructor: Called automatically when object goes out of scope
    ~DynamicMatrix() {
        deallocate();
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    // Create the matrix object
    DynamicMatrix mat(r, c);

    int choice;
    do {
        // Display menu
        cout << "\n--- Matrix Menu ---\n";
        cout << "1. Resize Matrix\n";
        cout << "2. Transpose Matrix\n";
        cout << "3. Print Matrix\n";
        cout << "4. Add 2 to Odd Indices\n";
        cout << "5. Deallocate Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int nr, nc;
            cout << "Enter new rows and columns: ";
            cin >> nr >> nc;
            mat.resize(nr, nc);
        } 
        else if (choice == 2) {
            mat.transpose();
            cout << "Matrix transposed.\n";
        } 
        else if (choice == 3) {
            mat.print();
        } 
        else if (choice == 4) {
            mat.addTwoToOddIndices();
            cout << "Added 2 to all odd index positions.\n";
        } 
        else if (choice == 5) {
            mat.deallocate();
            cout << "Matrix memory deallocated.\n";
        }

    } while (choice != 0); // Exit loop 

    cout << "Program ended.\n";
    return 0;
}

