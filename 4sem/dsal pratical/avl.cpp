#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Node structure for AVL Tree
struct Node {
    string key;
    string meaning;
    int height;
    Node* left;
    Node* right;

    Node(string k, string m) {
        key = k;
        meaning = m;
        height = 1;
        left = right = nullptr;
    }
};

// Helper to get height
int height(Node* n) {
    return n ? n->height : 0;
}

// Helper to get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotate
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert key in AVL tree
Node* insert(Node* node, string key, string meaning) {
    if (!node)
        return new Node(key, meaning);

    if (key < node->key)
        node->left = insert(node->left, key, meaning);
    else if (key > node->key)
        node->right = insert(node->right, key, meaning);
    else {
        cout << "Duplicate keyword not allowed: " << key << "\n";
        return node;
    }

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Balance the node
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Search for a keyword
void search(Node* root, string key) {
    if (!root) {
        cout << "Keyword not found: " << key << "\n";
        return;
    }

    if (key == root->key) {
        cout << "Meaning of '" << key << "' is: " << root->meaning << "\n";
    } else if (key < root->key) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// In-order traversal (sorted display)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << ": " << root->meaning << "\n";
    inorder(root->right);
}

// Main menu
int main() {
    Node* root = nullptr;
    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary using AVL Tree:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display All\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline buffer

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            root = insert(root, word, meaning);
            break;
        case 2:
            cout << "Enter word to search: ";
            getline(cin, word);
            search(root, word);
            break;
        case 3:
            cout << "Dictionary contents:\n";
            inorder(root);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
