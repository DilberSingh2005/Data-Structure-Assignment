#include <iostream>

using namespace std;

class Node 
{
public:
int data;
Node* next;
Node* prev;

Node(int data)
{
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

~Node()
{
    int value = this->data;
    if(next != NULL)
    {
        
        delete next;
        this->next =NULL;
    }
  cout<<"Object is deleted having value : "<<value<<endl;  
}
};

void insertAtHead(Node* &head,int d)
{

Node* temp = new Node(d);
if(head == NULL)
{
head = temp;
}
else
{
temp->next = head;
head->prev = temp;
head = temp;
}

}

void insertAtTail(Node* &tail,int d)
{
Node* temp = new Node(d);
if(tail == NULL)
{
tail = temp;
}
else
{
tail->next = temp;
temp->prev = tail;
tail = temp;
}

}

void insertAtPosition(Node* &head,Node* tail,int d,int position)
{
Node * nodeToInsert = new Node(d);
Node* temp = head;
int cnt = 1;

if(position == 1)
{
    insertAtHead(head,d);
    
}
else{

    while(cnt < position-1)
{
temp = temp->next;
cnt++;
}
    if(temp->next == NULL)
{
    insertAtTail(tail,d);
}
else{
nodeToInsert->next = temp->next;
temp->next->prev = nodeToInsert;
temp->next = nodeToInsert;
nodeToInsert->prev = temp;
}
}
}

void deleteAtPosition(Node* &head , int position)
{
    Node* curr = head;
    Node* prev =  NULL;
    if(position == 1)
    {
        curr->next->prev = NULL;
        head = curr->next;
        curr->next = NULL;
        delete curr;    
    }
    else
    {
        int cnt =1;
        while(cnt<position)
        {
            prev = curr;
            curr= curr->next;
            cnt++;
        }
       prev->next = curr->next;
       curr->next = NULL;
       curr->prev = NULL;
       delete curr;
    }
}

void deleteNodeValue(Node* &head , int value)
{
    Node* curr = head;
    Node* prev = NULL;

    if(curr->data == value && curr->prev == NULL)
    {
        curr->next->prev =NULL;
        head = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else
    {
      while(curr->data != value)
      {
        prev = curr;
        curr = curr->next;
      }
      prev->next = curr->next;
      curr->next = NULL;
      curr->prev = NULL;
      delete curr;

    }
}

bool nodeSearch(Node* head,int value)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}

Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        Node* forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
    }
    return prev;
}

bool palindrome(Node* head)
{
Node* slow = head;
Node* fast = head;

while(fast->next != NULL && fast->next->next != NULL)
{
    slow = slow->next;
    fast = fast->next->next;
}
Node* newHead = reverse(slow->next);
Node* first = head;
Node* second = newHead;

while(second != NULL)
{
    if(first->data != second->data)
    {
        reverse(newHead);
        return false;
    }
    first = first->next;
    second = second->next;
}
reverse(newHead);
return true;
}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,1);
    tail = head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    print(head);
  cout<<palindrome(head);
    return 0;
}