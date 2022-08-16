typedef struct Node
{
    int e;
    struct Node *left, *right;
} Node;
//添加新元素 返回根
Node add(Node root, int e)
{
    if (root == NULL)
    {
        Node new = (Node)malloc(sizeof(Node));
        new->e = e;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else
    {
        if (e > root->e)
        {
            root->right = add(root->right, e);
        }
        else if (e < root->e)
        {
            e->left = add(root->left, e);
        }
        return root;
    }
}
//查询是否存在
bool contans(Node root, int e)
{
    if (root == NULL)
        return false;
    if (root->e == e)
        return true;
    else if (e > root->e)
        return contans(root->right, e);
    else
        return contans(root->left, e);
}
//前序遍历
void preOrder(Node root)
{
    if (root == NULL)
        return;
    printf("%d", root->e);
    preOrder(root->left);
    preOrder(root->right);
}
//中序遍历
void inOrder(Node root)
{
    if (root == NULL)
        return;
    inOrder(root.left);
    printf("%d", root->e);
    inOrder(root->right);
}
//后序遍历
void postOrder(Node root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d", root->e);
}
//寻找最小元素
Node minimum(Node root)
{
    if (root == NULL)
        return;
    if (root.left == NULL)
        return root;
    return minimum(root.left);
}
//寻找最大元素
Node maxmum(Node root)
{
    if (root == NULL)
        return;
    if (root.right == NULL)
        return root;
    return maxmum(root.right);
}
//删除最小值 并返回删除后的根
Node removemin(Node root)
{
    if (root == NULL)
        return NULL;
    if (root.left == NULL)
    {
        Node rightNode = root.right;
        root.right = NULL;
        return rightNode;
    }
    node.left = removemin(root.left);
    return root;
}
// 删除最小值 并返回删除后的根
Node removemax(Node root)
{
    if (root == NULL)
        return NULL;
    if (root.right == NULL)
    {
        Node leftNode = root.right;
        root.left = NULL;
        return leftNode;
    }
    node.right = removemax(root.right);
    return root;
}
//删除任意节点（后继）
Node remove(Node root, int e)
{
    if (root == NULL)
        return;
    if (e < root.e)
    {
        root.left = remove(root.left, e);
        return root;
    }
    else if (e > root.e)
    {
        root.right = remove(root.right, e);
        return root;
    }
    else
    {
        if (root.left == NULL)
        {
            Node rightNode = root.right;
            root.right = NULL;
            return rightNode;
        }
        if (root.right == NULL)
        {
            Node leftNode = root.right;
            root.left = NULL;
            return leftNode;
        }
        Node successor = minimum(root.right);
        successor.right = removemin(root.right);
        successor.left = root.left;
        root.left = root.right = NULL;
    }
}