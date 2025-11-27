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

void insertAtTail(Node* &head, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool palindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverse(slow->next);

    Node* first = head;
    Node* second = newHead;

    while (second != NULL) {
        if (first->data != second->data) {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newHead);
    return true;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);

    print(head);

    if (palindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
