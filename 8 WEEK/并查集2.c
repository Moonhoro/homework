//初始化
int *Union(int *parent,int size){
    parent=malloc(sizeof(int)*size);
    for(int i=;i<size;i++){
        parent[i]=i;
    }
    return parent;
}
//查找元素p对于的编号
int find(int *parent,int p){
    while (p!=parent[p])
        p=parent[p];
    return  p;
}
//判断p，q是否为同一个集合
_Bool isConnected(int *parent,int p,int q){
    return  find(parent,p)==find(parent,q);
}
void unionElements(int p,int q,int size,int parent[]){
    int pRoot=find(parent,p);
    int qRoot=find(parent,q);
    if(pRoot==qRoot)return;
parent[pRoot]=qRoot;
}