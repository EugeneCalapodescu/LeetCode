#include "..\tools.h"

/*
    Given the roots of two binary trees root and subRoot, return true if
    there is a subtree of root with the same structure and node values of subRoot
    and false otherwise.

    A subtree of a binary tree tree is a tree that consists of
    a node in tree and all of this node's descendants.
    The tree tree could also be considered as a subtree of itself.

Solution: reuse recursively the IsSameTree function from LC-100

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


static bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q)
        return true;

    if (p && !q)
        return false;

    if (q && !p)
        return false;

    return p->val == q->val &&
        isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);
}

static bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (isSameTree(root, subRoot))
        return true;

    if (root && isSubtree(root->left, subRoot))
        return true;

    if (root && isSubtree(root->right, subRoot))
        return true;

    return false;
}

void lc_0572()
{

}