#include<iostream>

using namespace std;

class Node {
    public:
    int key;
    int count;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        count = 1;
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
            node -> count++;
            return node;
        }
        
        if (key < node -> key) {
            node -> left = insert(node -> left, key);
        } else {
            node -> right = insert(node -> right, key);
        } 
        
        return node;
    }

    void print(Node* node) {
        if (node -> left != nullptr) {
            print(node -> left);
        }
        cout << node -> key << " " << node -> count << endl;
        if (node -> right != nullptr) {
            print(node -> right);
        }
        return;
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
    tree -> print(tree -> root);
    return 0;
}