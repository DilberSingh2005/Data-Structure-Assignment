#include <iostream>

using namespace std;

class Node
{
public:
int data;
Node* next;

Node(int data)
{
this->data = data;
this->next = NULL;

}

~Node()
{
    int value = this->data;
    if(next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout<<"Object is deleted having value : "<<value<<endl;
}

};

void insertAfterValue(Node* &head ,int value ,int d)
{
    Node* temp = head;

    if(head == NULL)
    {
      Node* nodeToInsert = new Node(d);
      head = nodeToInsert;
      nodeToInsert->next = nodeToInsert;
      return;
    }
    else if(temp->next == temp && temp->data == value)
    {
        Node* nodeToInsert = new Node(d);
        temp->next = nodeToInsert;
        nodeToInsert->next = head;
        return;
    }
    else
    {
         do
    {
        if (temp->data == value)
        {
            Node* nodeToInsert = new Node(d);
            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << value << " not found in the list!" << endl;

    }

}

void print(Node* head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return; 
    }

    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void printAllNodes(Node* head)
{
  if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return; 
    }

    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout<<temp->data<<" ";
    cout << endl;
}


void deleteNode(Node* &head,int value)
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    if (curr->next == head && curr->data == value)
    {
        head = NULL;
        delete curr;
        cout << "Deleted the only node with value " << value << endl;
        return;
    }

    if (curr->data == value)
    {
        while (curr->next != head)
        {
            curr = curr->next;
        }
        Node* temp = head;
        curr->next = head->next;
        head = head->next;
        temp->next = NULL;
        delete temp;
        cout << "Deleted head node with value " << value << endl;
        return;
    }

    prev = head;
    curr = head->next;
    while (curr != head)
    {
        if (curr->data == value)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            cout << "Deleted node with value " << value << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Value " << value << " not found in the list!" << endl;
}

void sizeOfCircularLinkedList(Node* head)
{
    int len=0;
    Node* temp = head;
    if(head == NULL)
    {
        cout<<"Empty Link List : "<<endl;
    }
    else if(temp->next == temp)
    {
      len++;
      cout<<"Length of Link List is : "<<len<<endl;
    }
    else
    {
      do
      {
        len++;
        temp = temp->next;

      } while (temp != head);
      cout<<"Length of Link List is : "<<len<<endl;
    }
}

void circularCheck(Node* head)
{
     
     if(head == NULL)
     {
        cout<<"Link List is empty!"<<endl;
        return;
     }
     Node* temp = head->next;
     bool flag = true;
    while(temp != head)
    {
        if(temp == NULL || temp->next == NULL)
        {
            flag = false;
            break;
        }
        temp = temp->next;
    }
    if(flag == false)
    {
        cout<<"Link List is not circular!"<<endl;
    }
    else
    {
        cout<<"Link List is Circular!"<<endl;
    } 
}

void insertAtEnd(Node* &head,int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

pair<Node* , Node*> splitLinkList(Node* &head)
{
    Node* start = head;
Node* slow = head;
Node* fast = head;

while(fast->next != head && fast->next->next!=head)
{
    slow = slow->next;
    fast = fast->next->next;

}

Node* head1 = head;
Node* head3 = NULL;
while(head1 != slow->next)
{
    insertAtEnd(head3,head1->data);
    head1=head1->next;
}
Node* head2 = slow->next;
Node* temp = head2;
Node* head4 = NULL;
while(temp != start)
{
    insertAtEnd(head4,temp->data);
    temp=temp->next;
}

return{head3,head4};

}



int main()
{
    Node* head =NULL;
    insertAfterValue(head,0,1);
    insertAfterValue(head,1,2);
    insertAfterValue(head,2,3);
    insertAfterValue(head,3,4);
    insertAfterValue(head,4,5);
    print(head);
    pair<Node*, Node*> result = splitLinkList(head); 
    Node* head1 = result.first;
    Node* head2 = result.second;
    
    print(head1); 
    print(head2);
    return 0;
}