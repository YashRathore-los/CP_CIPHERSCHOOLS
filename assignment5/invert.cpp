class Solution {
public:
	void solution(TreeNode* root)
	{
		if (root == NULL)
			return;
		swap(root->left, root->right);
		solution(root->left);
		solution(root->right);
	}
	TreeNode* invertTree(TreeNode* root) {
		solution(root);
		return root;
	}
};