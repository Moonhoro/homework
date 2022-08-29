typedef struct {
int *sums;
int numsSize;
} NumArray;
int leftChild(int index){
    return  2*index+1;
}
int rightChild(int index){
    return 2*index+2;
}
//将数组arr[]中范围为[op,ed]以线段树的形式储存到tree[]中
void buildSegmentTree(int arr[],int tree[],int index,int op,int ed){
    if(op==ed){tree[index]=arr[op];return ;}
    int mid=(op+ed)/2;
    int leftTreeIndex= leftChild(index);
    int rightTreeIndex= rightChild(index);
    buildSegmentTree(arr,tree,leftTreeIndex,op,mid);
    buildSegmentTree(arr,tree,rightTreeIndex,mid+1,ed);
    tree[index]=tree[leftTreeIndex]+tree[rightTreeIndex];
}
//查询
int query(int tree[],int  queryL,int queryR,int treeIndex,int op,int ed){
    if(op==queryL&&ed==queryR)return tree[treeIndex];
    int mid=(op+ed)/2;
    int leftTreeIndex= leftChild(treeIndex);
    int rightTreeIndex= rightChild(treeIndex);
    if(queryL>=mid+1)return query(tree,queryL,queryR,rightTreeIndex,mid+1,ed);
    else if(queryR<=mid) return query(tree,queryL,queryR,leftTreeIndex,op,mid);
   int leftResult=query(tree,queryL,mid,leftTreeIndex,op,mid);
   int rightResult=query(tree,mid+1,queryR,rightTreeIndex,mid+1,ed);
    return  leftResult+rightResult;

}
void set(int index,int e,int arr[]){
    arr[index]=e;
}
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

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* tree=(NumArray*)malloc(sizeof(NumArray));
    tree->sums=malloc(sizeof(int)*numsSize*4);
    tree->numsSize=numsSize;
    buildSegmentTree(nums,tree->sums,0,0,numsSize-1);
return tree;
}

int numArraySumRange(NumArray* obj, int left, int right) {
return query(obj->sums,left,right,0,0,obj->numsSize-1);
}

void numArrayFree(NumArray* obj) {
free(obj->sums);
}

void numArrayUpdate(NumArray* obj, int index, int val) {
setTree(0,index,val,obj->sums,0,obj->numsSize-1);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/