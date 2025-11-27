#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int d) {
        data = d;
        next = prev = NULL;
    }
};

int sizeOfDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    DNode* head = new DNode(10);
    head->next = new DNode(20);
    head->next->prev = head;

    head->next->next = new DNode(30);
    head->next->next->prev = head->next;

    cout << "Size of Doubly Linked List: " << sizeOfDoubly(head) << endl;
    return 0;
}
