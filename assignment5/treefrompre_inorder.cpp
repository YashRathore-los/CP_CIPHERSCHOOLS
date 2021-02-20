TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int len = inorder.size();
	if (!len)
		return 0;
	std::map<int, int> lut;
	for (int i = 0; i < len; ++i)
		lut.insert(std::pair<int, int>(inorder[i], i));
	return buildTree(preorder, 0, inorder, 0, inorder.size(), lut);
}

TreeNode* buildTree(const vector<int>& preorder, int preStart, const vector<int>& inorder, int inStart, int len, const std::map<int, int> & lut) {
	int leftLen = lut.at(preorder[preStart]) - inStart;
	int rightLen = len - leftLen - 1;
	return new TreeNode(preorder[preStart],
	                    (leftLen > 0) ? buildTree(preorder, preStart + 1, inorder, inStart, leftLen, lut) : 0,
	                    (rightLen > 0) ? buildTree(preorder, preStart + 1 + leftLen, inorder, inStart + leftLen + 1, rightLen, lut) : 0);
}