#include <iostream>

using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node* up;
Node* down;

Node(int data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
    up = NULL;
    down = NULL;

}

};


int main()
{

    int rows, columns;
cout<<"Enter the number of rows :"<<endl;
cin>>rows;
cout<<"Enter the number of columns : "<<endl;
cin>>columns;

    int arr[rows][columns];

    cout<<"Enter elements of the array : "<<endl;
    for(int i = 0;i<rows;i++)
    {
        for(int j = 0; j<columns;j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    cout<<"Entered array : "<<endl;
    for(int i = 0;i<rows;i++)
    {
        for(int j = 0; j<columns;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    
    return 0;
}