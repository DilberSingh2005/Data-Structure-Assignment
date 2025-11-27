#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with value " << val << endl;
    }
};

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

int getLength(Node *head)
{
    int len = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{

    if (tail == NULL)
    {
        Node *temp = tail;
        tail = temp;
        head = temp;
    }
    Node *temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert At Start
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, int d)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    if (temp->data == d)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;

        temp->next = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != d)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value " << d << " not found!" << endl;
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    temp->next = temp->prev = NULL;
    delete temp;
}


int parity(int num)
{
int cnt1 = 0;
while(num != 0)
{
if(num%2 == 1)
{
    cnt1++;
}
num = num/2;
}
return cnt1;
}

void deleteEvenParityNode(Node* &head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        int val = temp->data;
        if (parity(val) % 2 == 0)
        {
            deleteNode(head, val);
        }

        temp = nextNode;
    }
}


int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 13);
    insertAtHead(head, tail, 8);
    insertAtTail(tail, head, 25);
    insertAtPosition(tail, head, 2, 99);
    insertAtPosition(tail, head, 4, 103);
    insertAtPosition(tail, head, 7, 101);
    insertAtPosition(tail, head, 8, 102);
    print(head);
    deleteEvenParityNode(head);
    print(head);


    return 0;
}