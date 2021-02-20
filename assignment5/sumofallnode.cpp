long int sumBT(Node* root)
{
    // Code here
    if (!root)
    {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    long int sum = 0;
    while (!q.empty())
    {
        Node* temp;
        temp = q.front();
        q.pop();
        sum = sum + temp->key;
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    return sum;
}