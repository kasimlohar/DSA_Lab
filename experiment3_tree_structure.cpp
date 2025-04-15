// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode {
public:
    string data;
    vector<TreeNode*> children;

    TreeNode(string data) {
        this->data = data;
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

void printTree(TreeNode* node, int level = 0) {
    if (!node) return;
    cout << string(level * 4, ' ') << node->data << endl;
    for (TreeNode* child : node->children) {
        printTree(child, level + 1);
    }
}

TreeNode* constructBookTree() {
    // Sample book structure
    TreeNode* root = new TreeNode("Book: Data Structures and Algorithms");

    // Chapters
    TreeNode* chapter1 = new TreeNode("Chapter 1: Introduction");
    TreeNode* chapter2 = new TreeNode("Chapter 2: Trees");

    // Sections in Chapter 1
    TreeNode* section1_1 = new TreeNode("Section 1.1: What is DSA?");
    TreeNode* section1_2 = new TreeNode("Section 1.2: Importance of DSA");
    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);

    // Sections in Chapter 2
    TreeNode* section2_1 = new TreeNode("Section 2.1: Binary Trees");
    TreeNode* section2_2 = new TreeNode("Section 2.2: Binary Search Trees");
    chapter2->addChild(section2_1);
    chapter2->addChild(section2_2);

    // Subsections in Section 2.1
    TreeNode* subsection2_1_1 = new TreeNode("Subsection 2.1.1: Definition");
    TreeNode* subsection2_1_2 = new TreeNode("Subsection 2.1.2: Properties");
    section2_1->addChild(subsection2_1_1);
    section2_1->addChild(subsection2_1_2);

    // Add chapters to the book
    root->addChild(chapter1);
    root->addChild(chapter2);

    return root;
}

void analyzeComplexity() {
    cout << "\nComplexity Analysis:" << endl;
    cout << "1. Time Complexity:" << endl;
    cout << "   - Tree construction: O(n), where n is the total number of nodes." << endl;
    cout << "   - Tree traversal (preorder): O(n), as each node is visited once." << endl;
    cout << "2. Space Complexity:" << endl;
    cout << "   - Tree construction: O(n), for storing n nodes." << endl;
    cout << "   - Tree traversal: O(h), where h is the height of the tree (stack space for recursion)." << endl;
}

int main() {
    cout << "Constructing the book tree..." << endl;
    TreeNode* bookTree = constructBookTree();
    cout << "\nPrinting the book tree (Preorder Traversal):" << endl;
    printTree(bookTree);
    analyzeComplexity();
    return 0;
}
