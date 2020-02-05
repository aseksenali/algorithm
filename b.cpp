#include <iostream>
#include <algorithm>

using namespace std;

struct Queue {
    int data[1000];
    int l, r;
    
    Queue() {
        l = r = 0;
    }

    void push(int n) {
        data[r] = n;
        r++;
        cout << "ok" << endl;
    }

    void pop() {
        if (l != r) {
            cout << data[l] << endl;
            l++;
        }
    }

    void front() {
        if (l != r) {
            cout << data[l] << endl;
            l++;
        }
    }

    void size() {
        cout << (r - l) << endl;
    }

    void clear() {
        r = l;
        cout << "ok" << endl;
    }

    void exit() {
        cout << "bye" << endl;
    }
};

int main() { 
    Queue *a = new Queue(); 
    string s; 
    while (cin >> s) { 
        if (s == "size") { 
            a -> size(); 
        } else if (s == "clear") { 
            a -> clear(); 
        } else if (s == "front") { 
            a -> front(); 
        } else if (s == "pop") { 
            a -> pop(); 
        } else if (s == "exit") { 
            a -> exit(); 
            break; 
        } else { 
            int c; 
            cin >> c; 
            a -> push(c); 
        } 
    } 
    return 0;
}