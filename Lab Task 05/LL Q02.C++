#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;   // stores data
    Node* next; // pointer to next node
};

// Function to print Circular Linked List
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    // Since it's circular, we stop when we come back to head
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// Insert a new node at the END of the list
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL}; // create new node
    if (head == NULL) {
        // if list empty, node points to itself
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    // traverse until last node (which points to head)
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;   // last node points to new node
    newNode->next = head;   // new node points back to head
}

// Insert a new node at the BEGINNING of the list
void insertBegin(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        // if list empty, node points to itself
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    // go to last node
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;   // new node points to old head
    temp->next = newNode;   // last node points to new node
    head = newNode;         // new node becomes head
}

// Insert at a specific POSITION (1-based index)
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 1) {
        // if position is 1, same as insert at beginning
        insertBegin(head, value);
        return;
    }
    Node* newNode = new Node{value, NULL};
    Node* temp = head;
    // move temp to (pos-1)th node
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    // insert newNode between temp and temp->next
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node by its VALUE
void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    // Case 1: if head node itself has the value
    if (head->data == value) {
        Node* temp = head;
        // find last node
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head->next == head) { // only one node in list
            delete head;
            head = NULL;
            return;
        }
        temp->next = head->next;  // last node points to 2nd node
        head = head->next;        // move head to next
        delete curr;              // delete old head
        return;
    }

    // Case 2: search for the node to delete
    do {
        prev = curr;
        curr = curr->next;
    } while (curr != head && curr->data != value);

    if (curr == head) {
        // came back to head → value not found
        cout << "Value not found" << endl;
        return;
    }

    // unlink and delete node
    prev->next = curr->next;
    delete curr;
}

// Main Function
int main() {
    Node* head = NULL; // start with empty list

    // Insert some nodes at END
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "Circular Linked List after inserting at end: ";
    printList(head);

    // Insert at BEGINNING
    insertBegin(head, 5);
    cout << "After inserting at beginning: ";
    printList(head);

    // Insert at POSITION 3
    insertAtPosition(head, 15, 3);
    cout << "After inserting 15 at position 3: ";
    printList(head);

    // DELETE a node (example: delete 20)
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    return 0;
}
