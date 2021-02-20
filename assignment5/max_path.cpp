  
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    return hasSum(root, targetSum);
}

bool hasSum(TreeNode *root, int targetSum) {
    if (root == nullptr) return false;

    // have to reach the end from root to some leaf node
    if (root->left == nullptr && root->right == nullptr && targetSum - root->val == 0)
        return true;

    bool left  = hasSum(root->left,  targetSum - root->val);
    bool right = hasSum(root->right, targetSum - root->val);

    return left || right;
}