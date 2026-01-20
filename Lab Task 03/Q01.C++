#include <iostream>
using namespace std;

class Node {
public:
    int Value;   // Stores the value of the node
    Node* next;  // Pointer to the next node in the list

    Node(int Val) {  // Constructor
        Value = Val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* Head; // Pointer to the start of the list
    Node* Tail; // Pointer to the end of the list

    LinkedList() {
        Head = nullptr;
        Tail = nullptr;
    }

    // Insert node at the end (used for input list creation)
    void Last(int Val) {
        Node* newNode = new Node(Val);
        if (Head == nullptr) {   // First element case
            Head = Tail = newNode;
        } else {
            Tail->next = newNode; // Attach new node at the end
            Tail = newNode;       // Update Tail
        }
    }

    // Rearrange so that all even nodes come before odd nodes
    void RearrangeEvenOdd() {
        if (Head == nullptr || Head->next == nullptr) return; // Empty or single-node list

        Node* evenHead = nullptr; 
        Node* evenTail = nullptr;
        Node* oddHead = nullptr;  
        Node* oddTail = nullptr;

        Node* Current = Head;

        // Traverse original list
        while (Current != nullptr) {
            if (Current->Value % 2 == 0) { // Even case
                if (evenHead == nullptr) {
                    evenHead = evenTail = Current;
                } else {
                    evenTail->next = Current;
                    evenTail = evenTail->next;
                }
            } else { // Odd case
                if (oddHead == nullptr) {
                    oddHead = oddTail = Current;
                } else {
                    oddTail->next = Current;
                    oddTail = oddTail->next;
                }
            }
            Current = Current->next; // Move to next node
        }

        // If no evens or no odds, nothing to rearrange
        if (evenHead == nullptr || oddHead == nullptr) return;

        // Link even list with odd list
        evenTail->next = oddHead;
        oddTail->next = nullptr;

        // Update Head and Tail
        Head = evenHead;
        Tail = oddTail;
    }

    // Print linked list
    void PrintList() {
        Node* Temp = Head;
        while (Temp != nullptr) {
            cout << Temp->Value;
            if (Temp->next != nullptr) cout << "->";
            Temp = Temp->next;
        }
        cout << "->NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* Current = Head;
        while (Current != nullptr) {
            Node* nextNode = Current->next;
            delete Current;
            Current = nextNode;
        }
        cout << "LinkedList destroyed Successfully" << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.Last(val); // build the list
    }

    cout << "\nORIGINAL LIST: ";
    list.PrintList();

    list.RearrangeEvenOdd(); // perform rearrangement

    cout << "\nMODIFIED LIST (Even before Odd): ";
    list.PrintList();

    return 0;
}
