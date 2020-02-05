#include<iostream>

using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

class BSTree {
    public:
    Node* root;
    int sz;

    BSTree() {
        root = nullptr;
        sz = 0;
    }

    int size() {
        return sz;
    }


    Node* insert(Node *node, int key) {
        if (node == nullptr) {
            node = new Node(key);
            sz++;
            return node;
        }

        if (key == node -> key) {
            return node;
        }
        
        if (key < node -> key) {
            node -> left = insert(node -> left, key);
        } else {
            node -> right = insert(node -> right, key);
        } 
        
        return node;
    }

    int secMax() {
        Node* node = root;
        while (node -> left != nullptr) {
            node = node -> left;
        }
        return node -> right -> key;
    }
};

int main() {
    BSTree *tree = new BSTree();
    int x;
    cin >> x;
    while (x != 0) { 
        tree -> root = tree -> insert(tree -> root, x);
        cin >> x;
    }
    cout << tree -> secMax();
    return 0;
}