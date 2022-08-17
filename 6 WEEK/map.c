//基于链表的映射的实现
typedef struct Node
{
    int k;
    int v;
    struct Node *next;
} Node;
//取值
Node *getNode(int k, Node head)
{
    Node cur = (Node *)malloc(sizeof(struct Node));
    cur = head.next;
    while (cur != NULL)
    {
        if (cur.k == k)
            return cur;
        cur = cur.next;
    }
    return;
}
//添加
void add(int key, int value, Node head)
{
    Node node = (Node *)malloc(sizeof(struct Node));
    node = getNode(key, head);
    if (node == NULL)
    {
        node.k = key;
        node.v = value;
        node.next = head.next;
        head.next = node;
    }
    else
    {
        node.v = value;
    }
}
//更新数据
void set(int k, int newValue, Node head)
{
    Node node = (Node *)malloc(sizeof(struct Node));
    node = getNode(key, head);
    if (node != NULL)
    {
        node.v = newValue;
    }
}
//删除
int remove(int k, Node head)
{
    Node node = (Node *)malloc(sizeof(struct Node));
    node = head;
    while (node.next != NULL)
    {
        if (node.next->k == key)
            break;
        node = node.next;
    }
    if (node.next != NULL)
    {
        Node delNode = (Node *)malloc(sizeof(struct Node));
        delNode = node.next;
        node.next = delNode.next;
        delNode.next = NULL;
        return delNode.v;
    }
    return NULL;
}
//基于二分搜索树实现
typedef struct Node
{
    int key, value;
    struct Node *left, *right;
} Node;
//添加
Node add(Node root, int key, int value)
{
    if (root == NULL)
    {
        Node new = (Node *)malloc(sizeof(Node));
        new->key = key;
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else
    {
        if (key > root->key)
        {
            root->right = add(root->right, key, value);
        }
        else if (e < root->key)
        {
            root->left = add(root->left, key, value);
        }
        else
        {
            root.value = value
        }
        return root;
    }
}
Node getNode(Node root, int key)
{
    if (root == NULL)
        return NULL;
    if (key == root.key)
        return root;
    if (key < root.key)
        return getNode(root.left, key);
    else
        return getNode(root.right, key);
}
void set(int key, int newValue, Node root)
{
    Node node = (Node *)malloc(sizeof(Node));
    node = getNode(root, key);
    if (node != NULL)
    {
        node.value = newValue;
    }
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
int remove(int key, Node root)
{
    Node node = (Node *)malloc(sizeof(Node));
    node = getNode(root, key);
    if (node == NULL)
        return;
    if (key < node.key)
    {
        node.left = remove(node.left, key);
        return node;
    }
    else if (key > node.key)
    {
        node.right = remove(node.right, key);
        return node;
    }
    else
    {
        if (root.left == NULL)
        {
            Node rightNode = (Node)malloc(sizeof(Node));
            rightNode = root.right;
            root.right = NULL;
            return rightNode;
        }
        if (root.right == NULL)
        {
            Node leftNode = (Node)malloc(sizeof(Node));
            leftNode = root.right;
            root.left = NULL;
            return leftNode;
        }
        Node successor = minimum(root.right);
        successor.right = removemin(root.right);
        successor.left = root.left;
        root.left = root.right = NULL;
    }
}