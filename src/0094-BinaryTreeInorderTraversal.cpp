/*

    LC 94 Binary Tree Inorder Traversal

    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    A faster way would be to pass the vector in argument, only one allocation this way

*/


#include "..\tools.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    if (root == NULL)
        return std::vector<int>();

    auto left = inorderTraversal(root->left);
    auto right = inorderTraversal(root->right);

    left.push_back(root->val);
    for (auto& val : right)
        left.push_back(val);

    return left;
}

void lc_0094()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    auto nodes = inorderTraversal(root);
}
