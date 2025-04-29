#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int no) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->data = no;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (no < root->data)
        root->left = insert(root->left, no);
    else
        root->right = insert(root->right, no);
    return root;
}

void search(Node* root, int no) {
    if (root == NULL) {
        cout << "Element not found\n";
        return;
    }
    if (root->data == no) {
        cout << "Element found\n";
    } else if (no < root->data) {
        search(root->left, no);
    } else {
        search(root->right, no);
    }
}

int longestPathLength(Node* root) {
    if (root == NULL)
        return 0;
    int left = longestPathLength(root->left);
    int right = longestPathLength(root->right);
    return max(left, right) + 1;
}

void swapTree(Node* root) {
    if (root == NULL)
        return;
    swapTree(root->left);
    swapTree(root->right);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    int ch, num;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Longest Path Length\n";
        cout << "4. Swap Left and Right (Mirror)\n";
        cout << "5. Find Minimum\n";
        cout << "6. Display (Preorder)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> num;
                root = insert(root, num);
                break;
            case 2:
                cout << "Enter number to search: ";
                cin >> num;
                search(root, num);
                break;
            case 3:
                cout << "Longest path length: " << longestPathLength(root) << "\n";
                break;
            case 4:
                swapTree(root);
                cout << "Tree swapped (mirrored)\n";
                break;
            case 5:
                cout << "Minimum element: " << findMin(root) << "\n";
                break;
            case 6:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << "\n";
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
