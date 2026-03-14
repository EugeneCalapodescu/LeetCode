/*

	LC 98. Validate Binary Search Tree

	Given the root of a binary tree, determine if it is a valid binary search tree (BST).

	A valid BST is defined as follows:

	The left
	subtree
	 of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.


	Example 1:
		Input: root = [2,1,3]
		Output: true

	Example 2:
		Input: root = [5,1,4,null,null,3,6]
		Output: false
		Explanation: The root node's value is 5 but its right child's value is 4.


	LC fastest solution:
		TreeNode* prev = nullptr;
		bool isValidBST(TreeNode* root)
		{
			if (root == nullptr)
				return true;
			if (!isValidBST(root->left))
				return false;
			if (prev && prev->val >= root->val)
				return false;

			prev = root;
			return isValidBST(root->right);
		}

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

static int min(TreeNode* root)
{
	if (!root)
		return INT_MAX;

	if (root->left)
		return min(root->left);

	return root->val;
}

static int max(TreeNode* root)
{
	if (!root)
		return INT_MIN;

	if (root->right)
		return min(root->right);

	return root->val;
}


bool isValidBST(TreeNode* root)
{
	if (!root)
		return true;

	if (!isValidBST(root->left) || !isValidBST(root->right))
		return false;

	if (root->left && max(root->left) >= root->val)
		return false;

	if (root->right && min(root->right) <= root->val)
		return false;

	return true;
}


void lc_0098()
{
	TreeNode* root = new TreeNode();
	printf("%d\n", isValidBST(root));

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	printf("%d\n", isValidBST(root));

	root = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right = new TreeNode(1);
	printf("%d\n", isValidBST(root));

	root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(6);
	printf("%d\n", isValidBST(root));


}


