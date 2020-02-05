#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node(int value) {
        this -> value = value;
    }
};

class BinaryTree {
    Node* root;
    BinaryTree(int a[]) {
        root = new Node(a[0]);
        
    }
};

int main() { 
    int n;
    cin >> n;
    int a[n];
    int j;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
    }
    return 0;
}