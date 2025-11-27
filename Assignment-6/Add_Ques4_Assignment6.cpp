#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *n = new Node(d);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

Node *reverseK(Node *head, int k)
{
    if (head == NULL || k <= 1)
        return head;

    Node *curr = head;
    Node *newHead = NULL;
    Node *ktail = NULL;

    while (curr != NULL)
    {
        int count = 0;
        Node *prev = NULL;
        Node *start = curr;

        while (curr != NULL && count < k)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            curr->prev = nextNode;
            prev = curr;
            curr = nextNode;
            count++;
        }

        if (newHead == NULL)
            newHead = prev;

        if (ktail != NULL)
        {
            ktail->next = prev;
            prev->prev = ktail;
        }

        ktail = start;
    }

    return newHead;
}

Node *correctPointer(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->prev != temp)
        {
            temp->next->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);

    int k = 3;

    head = reverseK(head, k);
    print(head);

    return 0;
}