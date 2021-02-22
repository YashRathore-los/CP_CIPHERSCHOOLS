class Solution {
public:
	int kthSmallest(TreeNode* root, int& k) {
		if (root == nullptr) return -1;
		int found = kthSmallest(root->left, k);
		if (found >= 0) return found;
		if (k == 1) return root->val;
		return kthSmallest(root->right, --k);
	}
};