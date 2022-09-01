//基于rank的优化
//初始化
typedef struct Union{
    int parent[];
    int rank[];
}Union,*Un;
Union *UnionBuild(Union *obj,int size){
    obj=malloc(sizeof(Union)*size);
    obj->parent= malloc(sizeof (int)*size);
    obj->rank= malloc(sizeof (int)*size);
    for(int i=0;i<size;i++){
        obj->parent[i]=i;
        obj->rank[i]=1;
    }
    return obj;
}
//查找元素p对于的编号
int find(Union *obj,int p){
    while (p!=obj->parent[p])
        p=obj->parent[p];
    return  p;
}
//判断p，q是否为同一个集合
_Bool isConnected(Union *obj,int p,int q){
    return  find(obj,p)==find(obj,q);
}
void unionElements(int p,int q,int size,Union *obj){
    int pRoot=find(obj,p);
    int qRoot=find(obj,q);
    if(pRoot==qRoot)return;
    if(obj->rank[pRoot]<obj->rank[qRoot]){
        obj->parent[pRoot]=obj->parent[qRoot];
    } else if(obj->rank[qRoot]<obj->rank[pRoot]){
        obj->parent[qRoot]=obj->parent[pRoot];}
    else{
        obj->parent[pRoot]=obj->parent[qRoot];
    obj->[pRoot]+=1;
    }
}

