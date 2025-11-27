#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head = NULL;

    void insertFirst(int val) {
        DNode* n = new DNode(val);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertLast(int val) {
        DNode* n = new DNode(val);
        if (!head) head = n;
        else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        DNode* n = new DNode(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        DNode* n = new DNode(val);
        n->next = temp;
        n->prev = temp->prev;
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        if (head->data == key) {
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


class CNode {
public:
    int data;
    CNode* next;
    CNode(int d) {
        data = d;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    CNode* head = NULL;

    void insertFirst(int val) {
        CNode* n = new CNode(val);
        if (!head) {
            head = n;
            n->next = n;
        } else {
            CNode* temp = head;
            while (temp->next != head) temp = temp->next;
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

    void insertLast(int val) {
        CNode* n = new CNode(val);
        if (!head) {
            head = n;
            n->next = n;
        } else {
            CNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* temp = head;
        CNode* prev = NULL;

        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        while (temp->data != key) {
            prev = temp;
            temp = temp->next;
            if (temp == head) return;
        }

        if (temp == head) {
            CNode* last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void search(int key) {
        if (!head) {
            cout << "Not Found\n";
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found\n";
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, type, val, key;

    while (true) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before (DLL only)\n5 Delete Node\n6 Search\n7 Display\nEnter: ";
        cin >> type;

        switch (type) {
        case 1:
            cin >> val;
            if (choice == 1) dll.insertFirst(val);
            else cll.insertFirst(val);
            break;

        case 2:
            cin >> val;
            if (choice == 1) dll.insertLast(val);
            else cll.insertLast(val);
            break;

        case 3:
            cin >> key >> val;
            if (choice == 1) dll.insertAfter(key, val);
            else cll.insertAfter(key, val);
            break;

        case 4:
            cin >> key >> val;
            if (choice == 1) dll.insertBefore(key, val);
            break;

        case 5:
            cin >> key;
            if (choice == 1) dll.deleteNode(key);
            else cll.deleteNode(key);
            break;

        case 6:
            cin >> key;
            if (choice == 1) dll.search(key);
            else cll.search(key);
            break;

        case 7:
            if (choice == 1) dll.display();
            else cll.display();
            break;
        }
    }
    return 0;
}
