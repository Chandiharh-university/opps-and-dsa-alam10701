#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Number of leaf nodes: " << countLeafNodes(root);

    return 0;
}
