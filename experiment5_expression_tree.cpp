// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() {
        root = nullptr;
    }

    // Build the expression tree from a prefix expression
    Node* buildTree(const string& prefix) {
        stack<Node*> st;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix[i];
            Node* newNode = new Node(ch);

            if (isOperator(ch)) {
                newNode->left = st.top(); st.pop();
                newNode->right = st.top(); st.pop();
            }
            st.push(newNode);
        }
        return st.top();
    }

    void buildTreeFromPrefix(const string& prefix) {
        root = buildTree(prefix);
    }

    // Non-recursive postorder traversal
    void postorderTraversal() {
        if (!root) return;

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* node = st1.top(); st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        cout << "Postorder Traversal: ";
        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
        cout << endl;
    }

    // Delete the entire tree
    void deleteTree(Node* node) {
        if (!node) return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void deleteTree() {
        deleteTree(root);
        root = nullptr;
    }

private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
};

int main() {
    ExpressionTree expTree;
    string prefixExpression;

    cout << "Enter a prefix expression: ";
    cin >> prefixExpression;

    expTree.buildTreeFromPrefix(prefixExpression);

    cout << "\nPerforming postorder traversal..." << endl;
    expTree.postorderTraversal();

    cout << "\nDeleting the tree..." << endl;
    expTree.deleteTree();

    if (!expTree.root) {
        cout << "Tree deleted successfully." << endl;
    } else {
        cout << "Tree deletion failed." << endl;
    }

    return 0;
}
