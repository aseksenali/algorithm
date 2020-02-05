#include <iostream>
#include <cmath>

using namespace std;

class Node {
    public:
    int key;
    int height;
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
    bool Balanced = true;
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
            node -> height = HeightOfTree(node);
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
        node -> height = HeightOfTree(node);
        return node;
    }

    int HeightOfTree(Node *node)
    {
        if ((!node -> left) && (!node -> right)) {
            return 0;
        }
        if (node == nullptr)
            return 0;

        int left, right;
        if (node -> left != nullptr) {
            left = HeightOfTree(node -> left);
        } else 
            left = -1;
        if (node -> right != nullptr) {
            right = HeightOfTree(node -> right);
        } else 
            right = -1;
        int max = left > right ? left : right;
        return max + 1;
    }

    void isBalanced(Node* node) {
        if ((!node -> left) && (!node -> right))
            return;

        if ((node -> left == nullptr) && (node -> right -> height > 0)) {
            Balanced = false;
            return;
        }
        if ((node -> right == nullptr) && (node -> left -> height > 0)) {
            Balanced = false;
            return;
        }
        if ((node -> left) && (node -> right)) {
            if (abs(node -> left -> height - node -> right -> height) > 1) {
                Balanced = false;
                return;
            }
        }
        if (node -> left) isBalanced(node -> left);
        if (node -> right) isBalanced(node -> right);
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
    tree -> isBalanced(tree -> root);
    if(tree -> Balanced) cout << "YES";
    else cout << "NO";
    return 0;
}