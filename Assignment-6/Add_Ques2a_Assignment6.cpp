#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int value)
{

    if (tail == NULL)
    {
        Node *newNode = new Node(value);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(value);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{

    Node *temp = tail;
    do
    {

        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{

    if (tail == NULL)
    {
        cout << "List is empty";
        return;
    }
    else
    {
       
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
      
        if(tail == curr)
        {
            tail=prev;
                }
              
                if(curr == prev)
                {
tail =NULL;
                }
        curr->next = NULL;
        delete curr;
    }
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

void deleteEvenParityNode(Node* &tail)
{
    if (tail == NULL)
    {
        cout << "Empty Linked List!" << endl;
        return;
    }

    Node* temp = tail->next;
    Node* start = tail->next;

    do
    {
        Node* nextNode = temp->next;
        int p = parity(temp->data);

        if (p % 2 == 0)
        {
            int val = temp->data;
            deleteNode(tail, val);
            if (tail == NULL) return;
        }
        temp = nextNode;
    } while (tail != NULL && temp != start);
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);

    insertNode(tail, 3, 5);

    insertNode(tail, 5, 7);

    insertNode(tail, 7, 9);

    insertNode(tail, 5, 6);

    insertNode(tail, 9, 10);

    insertNode(tail, 3, 4);
    print(tail);

    deleteEvenParityNode(tail);
    print(tail);
    return 0;
}