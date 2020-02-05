#include <iostream> 
#include <algorithm> 

using namespace std; 

struct Stack { 
    int data[1000000]; 
    int len; 
    Stack() { 
        len = 0; 
    } 

    void push(int n) { 
        data[len++] = n; 
        cout << "ok" << endl; 
    } 

    void pop() { 
        if (len > 0) { 
            cout << data[len - 1] << endl; 
            len--; 
        } else { 
            cout << "error" << endl; 
        } 
    } 

    void back() { 
        if (len > 0) { 
            cout << data[len - 1] << endl; 
        } else { 
            cout << "error" << endl; 
        } 
    } 

    void clear() { 
        len = 0; 
        cout << "ok" << endl; 
    } 

    void size() { 
        cout << len << endl; 
    } 

    void exit() { 
        cout << "bye"; 
    } 
}; 

int main() { 
    Stack *a = new Stack(); 
    string s; 
    while (cin >> s) { 
        if (s == "size") { 
            a -> size(); 
        } else if (s == "clear") { 
            a -> clear(); 
        } else if (s == "back") { 
            a -> back(); 
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
}