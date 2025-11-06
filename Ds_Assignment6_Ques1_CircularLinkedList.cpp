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

int main()
{
    Node* head =NULL;
    print(head);
    insertAfterValue(head,0,1);
    print(head);
    insertAfterValue(head,1,2);
    insertAfterValue(head,2,3);
    insertAfterValue(head,3,4);
    print(head);

    printAllNodes(head);

    deleteNode(head,4);
    print(head);

    sizeOfCircularLinkedList(head);

    circularCheck(head);
    return 0;
}