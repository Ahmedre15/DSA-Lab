#include <iostream>
using namespace std;

// Node structure for Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to print Circular Doubly Linked List
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// Insert a node at the END
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, NULL};
    if (head == NULL) {
        // first node points to itself in both directions
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    Node* last = head->prev; // last node is before head
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Insert a node at the BEGINNING
void insertBegin(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, NULL};
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    Node* last = head->prev; // last node
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode; // new node becomes head
}

// Insert at a specific POSITION (1-based index)
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 1) {
        insertBegin(head, value);
        return;
    }
    Node* newNode = new Node{value, NULL, NULL};
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;
}

// Delete a node by VALUE
void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;
    Node* prevNode = NULL;

    // Case 1: If head node is to be deleted
    if (head->data == value) {
        if (head->next == head) {
            // only one node
            delete head;
            head = NULL;
            return;
        }
        Node* last = head->prev;
        Node* newHead = head->next;
        last->next = newHead;
        newHead->prev = last;
        delete head;
        head = newHead;
        return;
    }

    // Case 2: search for node
    do {
        if (curr->data == value) {
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete curr;
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "Value not found" << endl;
}

// Main Function
int main() {
    Node* head = NULL;

    // Insert at END
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    cout << "After inserting at end: ";
    printList(head);

    // Insert at BEGINNING
    insertBegin(head, 5);
    cout << "After inserting at beginning: ";
    printList(head);

    // Insert at POSITION 3
    insertAtPosition(head, 15, 3);
    cout << "After inserting 15 at position 3: ";
    printList(head);

    // DELETE a node (example 20)
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    return 0;
}
