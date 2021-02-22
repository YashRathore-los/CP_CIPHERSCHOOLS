struct Node *
findleftmost(struct Node *node)
{
    if (node->left)
        node = findleftmost(node->left);
    return node;
}


struct Node* inorderSuccessor(struct Node* node)
{
    struct Node *parent = NULL;

    if (node->right)
        return findleftmost(node->right);

    parent = node->parent;
    while (parent && parent->right == node) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}