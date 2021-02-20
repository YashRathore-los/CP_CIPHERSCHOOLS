int next_closing(string s, int x)
{
    stack<char>stk;
    stk.push(s[x]);
    int i = x + 1;
    while (!stk.empty())
    {
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            stk.pop();
        }
        i++;
    }
    return i - 1;
}
TreeNode *helper(string s, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int i = start;
    while (i <= end && s[i] != ')' && s[i] != '(')
    {
        i++;
    }
    int value = stoi(s.substr(start, i - start));
    TreeNode *root = new TreeNode(value);
    if (start == end)
    {
        return root;
    }
    int left_start = i + 1;
    int left_end = next_closing(s, i) - 1;
    root->left = helper(s, left_start, left_end);
    root->right = helper(s, left_end + 3, end - 1);
    return root;
}
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root)
        {
            return "()";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return "(" + to_string(root->val) + left + right + ")";
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data == "")
        {
            return NULL;
        }
        data.erase(data.begin());
        data.erase(data.begin() + data.length() - 1);
        return helper(data, 0, data.length() - 1);
    }
};