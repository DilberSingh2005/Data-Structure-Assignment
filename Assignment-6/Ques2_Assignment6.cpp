#include <iostream>
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

class CircularLinkedList {
public:
    Node* head = NULL;

    void insert(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = n;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    void displayRepeatHead() {
        if (!head) return;

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data;  
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);

    cll.displayRepeatHead();  

    return 0;
}
