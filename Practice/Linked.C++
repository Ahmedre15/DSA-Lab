#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addnode(int d) {
        Node* newnode = new Node(d);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void rearrange() {
        if (head == NULL || head->next == NULL) return;

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            temp = temp->next;
        }

        if (evenHead != NULL) {
            head = evenHead;
            evenTail->next = oddHead;
        } else {
            head = oddHead;
        }

        if (oddTail != NULL) {
            oddTail->next = NULL;
            tail = oddTail;
        } else {
            tail = evenTail;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addnode(10);
    list.addnode(15);
    list.addnode(20);
    list.addnode(25);
    list.addnode(30);

    cout << "Original List: ";
    list.display();

    list.rearrange();   // ✅ corrected call

    cout << "Rearranged (Even first, Odd later): ";
    list.display();
}
