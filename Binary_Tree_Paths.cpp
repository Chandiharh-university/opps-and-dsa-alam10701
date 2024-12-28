#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPaths(TreeNode* node, string path, vector<string>& paths) {
    if (node == NULL) return;

    path += to_string(node->val);
    
    if (node->left == NULL && node->right == NULL) {
        paths.push_back(path);
    } else {
        path += "->";
        findPaths(node->left, path, paths);
        findPaths(node->right, path, paths);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> paths = binaryTreePaths(root);
    
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
