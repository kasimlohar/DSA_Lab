// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    // Insert a new node into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Find the height of the BST
    int findHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }

    int findHeight() {
        return findHeight(root);
    }

    // Find the minimum value in the BST
    int findMin(TreeNode* node) {
        if (node == nullptr) {
            throw runtime_error("Tree is empty.");
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int findMin() {
        return findMin(root);
    }

    // Mirror the BST
    void mirror(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    void mirror() {
        mirror(root);
    }

    // Search for a specific value in the BST
    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    bool search(int value) {
        return search(root, value);
    }

    // Inorder traversal to print the BST
    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int n, value;

    cout << "Enter the number of elements to insert into the BST: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(value);
    }

    cout << "\nInorder traversal of the BST: ";
    bst.inorder();

    cout << "Height of the BST: " << bst.findHeight() << endl;

    try {
        cout << "Minimum value in the BST: " << bst.findMin() << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "Enter a value to search in the BST: ";
    cin >> value;
    if (bst.search(value)) {
        cout << value << " is found in the BST." << endl;
    } else {
        cout << value << " is not found in the BST." << endl;
    }

    cout << "\nMirroring the BST..." << endl;
    bst.mirror();
    cout << "Inorder traversal after mirroring: ";
    bst.inorder();

    return 0;
}
