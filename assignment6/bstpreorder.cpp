class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if (preorder.size() == 0)
        {
            return NULL;
        }
        return BST(preorder, 0, preorder.size() - 1);
    }

    TreeNode* BST(vector<int> v, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int partition;
        for (partition = start; partition <= end; partition++)
        {
            if (v[start] < v[partition])
            {
                break;
            }
        }

        TreeNode* temp = new TreeNode(v[start]);
        cout << temp->val << " ";
        temp->left = BST(v, start + 1, partition - 1);
        temp->right = BST(v, partition, end);

        return temp;
    }
};