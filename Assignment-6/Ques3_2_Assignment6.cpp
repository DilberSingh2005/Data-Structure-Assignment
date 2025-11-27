#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;

    CNode(int d) {
        data = d;
        next = NULL;
    }
};

int sizeOfCircular(CNode* head) {
    if (head == NULL) return 0;

    int count = 0;
    CNode* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    CNode* head = new CNode(5);
    CNode* n2 = new CNode(15);
    CNode* n3 = new CNode(25);

    head->next = n2;
    n2->next = n3;
    n3->next = head;

    cout << "Size of Circular Linked List: " << sizeOfCircular(head) << endl;

    return 0;
}
