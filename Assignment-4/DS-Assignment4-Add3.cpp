#include <bits/stdc++.h>
using namespace std;

bool canBeSorted(queue<int> &q) {
    stack<int> st;
    queue<int> result;
    int prev = INT_MIN;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Move smaller elements from stack to result
        while (!st.empty() && st.top() < curr) {
            if (prev > st.top()) return false;
            prev = st.top();
            result.push(st.top());
            st.pop();
        }
        st.push(curr);
    }

    // Empty remaining stack
    while (!st.empty()) {
        if (prev > st.top()) return false;
        prev = st.top();
        result.push(st.top());
        st.pop();
    }

    // Restore sorted queue
    q = result;
    return true;
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (canBeSorted(q)) {
        cout << "Yes, queue can be sorted.\nSorted queue: ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    } else {
        cout << "No, queue cannot be sorted using a stack.";
    }

    return 0;
}

