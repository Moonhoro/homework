void dfs(const struct TreeNode *root, int height, int *curVal, int *curHeight)
{
    if (root == NULL)
    {
        return;
    }
    height++;
    dfs(root->left, height, curVal, curHeight);
    dfs(root->right, height, curVal, curHeight);
    if (height > *curHeight)
    {
        *curHeight = height;
        *curVal = root->val;
    }
}
int findBottomLeftValue(struct TreeNode *root)
{
    int curVal, curHeight = 0;
    dfs(root, 0, &curVal, &curHeight);
    return curVal;
}