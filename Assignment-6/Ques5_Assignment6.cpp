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

bool isCircular(Node* head) {
    if (head == NULL)
        return true;
    else {
        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        if (temp == head)
            return true;
        else
            return false;
    }
}

int main() {
    Node* head1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    head1->next = n2;
    n2->next = n3;
    n3->next = head1;

    if (isCircular(head1))
        cout << "Circular\n";
    else
        cout << "Not Circular\n";

    Node* head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(25);

    if (isCircular(head2))
        cout << "Circular\n";
    else
        cout << "Not Circular\n";

    return 0;
}
