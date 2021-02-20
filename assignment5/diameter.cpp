int getheight(TreeNode* root, int &dia)
{
	if (root == NULL)
		return 0;
	int hleft = 0, hright = 0;
	if (root->left != NULL)
		hleft = 1 + getheight(root->left, dia);
	if (root->right != NULL)
		hright = 1 + getheight(root->right, dia);
	if (dia < hleft + hright)
		dia = hleft + hright;
	return max(hleft, hright);
}
int diameterOfBinaryTree(TreeNode* root) {
	int dia = 0;
	getheight(root, dia);
	return dia;
}