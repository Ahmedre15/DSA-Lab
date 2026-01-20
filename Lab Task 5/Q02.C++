#include <iostream>
#include <string>
using namespace std;

// Recursive helper function to build parentheses
void buildBrackets(string made, int open, int close, int limit) {
    // If we've used all pairs, print the current combination
    if (made.length() == limit * 2) {
        cout << made << endl;
        return;
    }

    // Try adding an opening bracket if we still can
    if (open < limit)
        buildBrackets(made + "(", open + 1, close, limit);

    // Add a closing bracket only if it keeps the string valid
    if (close < open)
        buildBrackets(made + ")", open, close + 1, limit);
}

// Main function
int main() {
    int n = 3;  // Number of pairs of brackets

    cout << "All valid combinations of parentheses for n = " << n << ":\n\n";
    buildBrackets("", 0, 0, n);

    return 0;
}
