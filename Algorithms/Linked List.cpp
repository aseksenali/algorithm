#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int a) {
        value = a;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void insert(int a) {
        Node* node = new Node(a);
        if (head == NULL) {
            head = tail = node;
            return;
        }
        tail -> next = node;
        tail = node;
    }

    void remove(int n) {
        Node* node = head;
        for (int i = 1; i < n; i++) {
            node = node -> next;
        }

        node -> next = node -> next -> next;
    }

    int size() {
        return sz;
    }

    int select(int n) {
        Node* node = head;
        for (int i = 0; i < n; i++) {
            return node -> value;
        }
    }

    int top() {
        return tail -> value;
    }
};

int main() {
    LinkedList* list = new LinkedList();
    list -> insert(2);
    list -> insert(3);
    list -> insert(5);
    list -> insert(4);
    list -> remove(2);
    cout << list -> top();
}