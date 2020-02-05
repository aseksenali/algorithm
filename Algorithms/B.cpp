#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
    int data;
    Node* con[2];

    Node(int value) {
        data = value;
        con[0]= NULL;
        con[1] = NULL;
    }
};

class Deque
{
    private:
    int sz;
    Node* head;
    Node* tail;

    public:
    Deque() {
        head = tail = NULL;
        sz = 0;
    }

    void front() {
        if (head == NULL) {
            cout << ";(" << endl; 
            return;
        }

        Node* con = head -> con[0] == NULL ? head -> con[1] : head -> con[0];
        cout << head -> data << endl;
        if (con == NULL) {
            head = tail = NULL;
        }
        else {
            if (con -> con[0] == head)
                con -> con[0] = NULL;
            else
                con -> con[1] = NULL;
            head = con;
        }
        sz--;
    }

    void back() {
        if (tail == NULL) {
            cout << ";(" << endl; 
            return;
        }

        Node* con = tail -> con[0] == NULL ? tail -> con[1] : tail -> con[0];
        cout << tail -> data << endl;
        if (con == NULL) {
            tail = head = NULL;
        }
        else {
            if (con -> con[0] == tail)
                con -> con[0] = NULL;
            else
                con -> con[1] = NULL;
            tail = con;
        }
        sz--;
    }

    int size() {
        return sz;
    }

    void push_front(int value) {
        sz++;
        Node* node = new Node(value);
        if (head == NULL) {
            head = tail = node;
            return;
        }
        if (head -> con[0] == NULL)
            head -> con[0] = node;
        else
            head -> con[1] = node;
        node -> con[0] = head;
        head = node;
    }

    void push_back(int value) {
        sz++;
        Node* node = new Node(value);
        if (tail == NULL) {
            head = tail = node;
            return;
        }
        if (tail -> con[0] == NULL)
            tail -> con[0] = node;
        else
            tail -> con[1] = node;
        node -> con[0] = tail;
        tail = node;
    }
    
    void reverse() {
        Node* tmp = head;
        head = tail;
        tail = tmp;
    }
};

int main() 
{
    string s;
    int n, a, i;

    Deque* deque = new Deque();

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> s;
        if (s == "back") {
            deque -> back();
        }
        else if (s == "front") {
            deque -> front();
        }
        else if (s == "push_back") {
            cin >> a; 
            deque -> push_back(a);
        }
        else if (s == "push_front") {
            cin >> a; 
            deque -> push_front(a);
        }
        else if (s == "reverse") {
            deque -> reverse();
        }
    }
    return 0;
}