#include <iostream>
using namespace std;

class qIMParr {
    int q[10];
    int size = 10;
    int start = -1;
    int end = -1;
    int curr_size = 0;

public:
    void push(int x) {
        if (end == size - 1) {
            cout << "The queue is full!" << endl;
            return;
        }
        if (start == -1) start = 0; // first element
        q[++end] = x;
        curr_size++;
    }

    void pop() {
        if (curr_size == 0) {
            cout << "The queue is empty!" << endl;
            return;
        }
        if (start == end) {
            start = -1;
            end = -1;
        } else {
            start++;
        }
        curr_size--;
    }

    bool isEmpty() {
        return curr_size == 0;
    }

    bool isFull() {
        return end == size - 1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return q[start];
    }

    int top() { // added for compatibility with your main()
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return q[end];
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        for (int i = start; i <= end; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    qIMParr q;
    q.push(10);
    cout << q.top() << endl;   // prints last inserted (10)
    q.push(20);
    q.pop();
    cout << q.top() << endl;   // prints last inserted (20)
    cout << q.peek();          // prints front element
    return 0;
}

