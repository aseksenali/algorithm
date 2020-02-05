#include<iostream>

using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BSTree {
    public:
    Node* root;
    int sz;
    BSTree() {
        root = NULL;
    }

    int size() {
        return sz;
    }


    Node* insert(Node *node, int key) {
        if (node == NULL) {
            node =  new Node(key);
            return node;
        }

        if (key < node -> key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        } 
        
        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    Node* minimum(Node* node) {
        if (node->left == NULL) {
            return node;
        } else {
            return minimum(node->left);
        }
    }

    Node* maximum(Node* node) {
        if (node->right == NULL) {
            return node;
        } else {
            return maximum(node->left);
        }
    }

    Node* del(Node* node, int key) {
        if (node == NULL) {
            return NULL;
        }
        if (key < node -> key) {
            node->left = del(node->left, key);
        } else if (key > node->key) {
            node->right = del(node->right, key);
        } else if (node->left != NULL && node->right != NULL) {
            node->key = minimum(node->right)->key;
            node->right = del(node->right, node->key);
        } else if (node->left != NULL) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
};

int main() {
    BSTree *tree = new BSTree();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree->root=tree->insert(tree->root, x);
    }
    tree -> inorder(tree -> root);
    return 0;
}