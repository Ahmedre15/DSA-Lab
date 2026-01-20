#include <iostream>
using namespace std;

struct Node {
    char text[100];
    Node* next;
};

Node* table[1000];

void copyText(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool textsEqual(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return a[i] == b[i];
}

int hashFunc(char s[]) {
    int h = 0, i = 0;
    while (s[i] != '\0') {
        h = (h * 31 + s[i]) % 1000;
        i++;
    }
    return h;
}

bool exists(char s[]) {
    int h = hashFunc(s);
    Node* temp = table[h];
    while (temp != NULL) {
        if (textsEqual(temp->text, s))
            return true;
        temp = temp->next;
    }
    return false;
}

void insertPost(char s[]) {
    int h = hashFunc(s);
    Node* newNode = new Node;
    copyText(newNode->text, s);
    newNode->next = table[h];
    table[h] = newNode;
}

int main() {
    char s[100];

    while (true) {
        if (!cin.getline(s, 100)) break;

        if (exists(s)) {
            cout << "DUPLICATE" << endl;
        } else {
            cout << "NEW" << endl;
            insertPost(s);
        }
    }

    return 0;
}
