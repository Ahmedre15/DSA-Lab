#include <iostream>
using namespace std;

struct Incident {
    int severity;
    int timestamp;
    char desc[100];
};

Incident heapArr[100];
int heapSize = 0;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2*i + 1; }
int rightChild(int i) { return 2*i + 2; }

// manual copy
void copyText(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// compare priority
bool higherPriority(Incident a, Incident b) {
    if (a.severity != b.severity)
        return a.severity > b.severity;
    return a.timestamp < b.timestamp;
}

void heapifyUp(int i) {
    while (i > 0 && higherPriority(heapArr[i], heapArr[parent(i)])) {
        Incident temp = heapArr[i];
        heapArr[i] = heapArr[parent(i)];
        heapArr[parent(i)] = temp;
        i = parent(i);
    }
}

void heapifyDown(int i) {
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heapSize && higherPriority(heapArr[l], heapArr[largest]))
        largest = l;

    if (r < heapSize && higherPriority(heapArr[r], heapArr[largest]))
        largest = r;

    if (largest != i) {
        Incident temp = heapArr[i];
        heapArr[i] = heapArr[largest];
        heapArr[largest] = temp;
        heapifyDown(largest);
    }
}

void addIncident(int severity, int timestamp, char desc[]) {
    Incident inc;
    inc.severity = severity;
    inc.timestamp = timestamp;
    copyText(inc.desc, desc);

    heapArr[heapSize] = inc;
    heapifyUp(heapSize);
    heapSize++;
}

void dispatchIncident() {
    if (heapSize == 0) {
        cout << "NO INCIDENTS" << endl;
        return;
    }

    cout << heapArr[0].severity << " "
         << heapArr[0].timestamp << " "
         << heapArr[0].desc << endl;

    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int main() {
    char command[20];

    while (cin >> command) {

        if (command[0]=='A' && command[1]=='D' && command[2]=='D') {
            int sev, time;
            char desc[100];

            cin >> sev >> time;
            cin.ignore();

            int i = 0;
            char c;
            while (true) {
                c = cin.get();
                if (c=='\n' || c==EOF) break;
                desc[i++] = c;
            }
            desc[i] = '\0';

            addIncident(sev, time, desc);
        }

        else if (command[0]=='D' && command[1]=='I') {
            dispatchIncident();
        }
    }

    return 0;
}
