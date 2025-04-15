// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class AVLNode {
public:
    string key;
    string meaning;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(string k, string m) : key(k), meaning(m), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    // Get the height of a node
    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    // Get the balance factor of a node
    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotate
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    // Left rotate
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    // Insert a new (key, meaning) pair
    AVLNode* insert(AVLNode* node, string key, string meaning) {
        if (!node) return new AVLNode(key, meaning);

        if (key < node->key) {
            node->left = insert(node->left, key, meaning);
        } else if (key > node->key) {
            node->right = insert(node->right, key, meaning);
        } else {
            throw runtime_error("Duplicate key insertion is not allowed.");
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find the node with the minimum key
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left) {
            current = current->left;
        }
        return current;
    }

    // Delete a keyword
    AVLNode* deleteNode(AVLNode* node, string key) {
        if (!node) return node;

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (!node->left || !node->right) {
                AVLNode* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }

            AVLNode* temp = minValueNode(node->right);
            node->key = temp->key;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->key);
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Balancing the tree
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order traversal for ascending order
    void inOrder(AVLNode* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->key << ": " << node->meaning << endl;
        inOrder(node->right);
    }

    // Reverse in-order traversal for descending order
    void reverseInOrder(AVLNode* node) {
        if (!node) return;
        reverseInOrder(node->right);
        cout << node->key << ": " << node->meaning << endl;
        reverseInOrder(node->left);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(string key, string meaning) {
        root = insert(root, key, meaning);
    }

    void deleteKey(string key) {
        root = deleteNode(root, key);
    }

    void update(string key, string newMeaning) {
        AVLNode* current = root;
        while (current) {
            if (key == current->key) {
                current->meaning = newMeaning;
                return;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        throw runtime_error("Key not found.");
    }

    void displayAscending() {
        cout << "Dictionary in ascending order:" << endl;
        inOrder(root);
    }

    void displayDescending() {
        cout << "Dictionary in descending order:" << endl;
        reverseInOrder(root);
    }
};

int main() {
    AVLTree dictionary;
    int choice;
    string key, meaning;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a new (keyword, meaning) pair\n";
        cout << "2. Delete a keyword\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Display all entries in ascending order\n";
        cout << "5. Display all entries in descending order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                try {
                    dictionary.insert(key, meaning);
                    cout << "Inserted successfully." << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 2:
                cout << "Enter keyword to delete: ";
                cin >> key;
                try {
                    dictionary.deleteKey(key);
                    cout << "Deleted successfully." << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                try {
                    dictionary.update(key, meaning);
                    cout << "Updated successfully." << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 4:
                dictionary.displayAscending();
                break;

            case 5:
                dictionary.displayDescending();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
