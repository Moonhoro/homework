int leftChild(int index)
{
    return 2 * index + 1;
}
int rightChild(int index)
{
    return 2 * index + 2;
}
//将数组arr[]中范围为[op,ed]以线段树的形式储存到tree[]中
void buildSegmentTree(int arr[], int tree[], int index, int op, int ed)
{
    if (op == ed)
    {
        tree[index] = arr[op];
        return;
    }
    int mid = (op + ed) / 2;
    int leftTreeIndex = leftChild(index);
    int rightTreeIndex = rightChild(index);
    buildSegmentTree(arr, tree, leftTreeIndex, op, mid);
    buildSegmentTree(arr, tree, rightTreeIndex, mid + 1, ed);
    tree[index] = tree[leftTreeIndex] + tree[rightTreeIndex];
}
//查询
int query(int tree[], int queryL, int queryR, int treeIndex, int op, int ed)
{
    if (op == queryL && ed == queryR)
        return tree[treeIndex];
    int mid = (op + ed) / 2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    if (queryL >= mid + 1)
        return query(tree, queryL, queryR, rightTreeIndex, mid + 1, ed);
    else if (queryR <= mid)
        return query(tree, queryL, queryR, leftTreeIndex, op, mid);
    int leftResult = query(tree, queryL, mid, leftTreeIndex, op, mid);
    int rightResult = query(tree, mid + 1, queryR, rightTreeIndex, mid + 1, ed);
    return leftResult + rightResult;
}
//将arr的index位置的值，更新为e，
void set(int index,int e,int arr[]){
    arr[index]=e;
}
//将以treeIndex为根的线段树中index的值更新为e.
void setTree(int treeIndex,int index,int e,int *tree,int op,int ed){
    if(op==ed) {
        tree[treeIndex] = e;
        return;
    }
    int mid = (op + ed) / 2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    if(index>=mid+1)setTree(rightTreeIndex,index,e,tree,mid+1,ed);
    else setTree(leftTreeIndex,index,e,tree,op,mid);
    tree[treeIndex]=tree[leftTreeIndex]+tree[rightTreeIndex];
}