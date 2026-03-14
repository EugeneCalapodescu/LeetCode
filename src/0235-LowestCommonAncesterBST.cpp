/*

	LC 235 Lowest Common Ancestor of a Binary Search Tree


	Given a binary search tree(BST), find the lowest common ancestor(LCA) node of two given nodes in the BST.

	According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes pand q as
	the lowest node in T that has both pand q as descendants(where we allow a node to be a descendant of itself).”

	Example 1 :
		Input : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 8
		Output : 6
		Explanation : The LCA of nodes 2 and 8 is 6.

	Example 2 :
		Input : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 4
		Output : 2
		Explanation : The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

*/

#include "..\tools.h"
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (p == nullptr || q == nullptr)
		return nullptr;

	if (p == root)
		return p;

	if (q == root)
		return p;

	if (p->val > q->val)
		return lowestCommonAncestor(root, q, p);

	if (p->val < root->val && q->val > root->val)
		return root;

	if (p->val < root->val)
		return lowestCommonAncestor(root->left, p, q);

	return lowestCommonAncestor(root->right, p, q);
}

void lc_0235()
{
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	lowestCommonAncestor(root, root->left, root->right);

}