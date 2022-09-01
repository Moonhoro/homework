//初始化
int *Union(int *id,int size){
    id=malloc(sizeof(int)*size);
    for(int i=;i<size;i++){
        id[i]=i;
    }
    return id;
}
//查找元素p对于的编号
int find(int *id,int p){

    return id[p];
}
//判断p，q是否为同一个集合
_Bool isConnected(int *id,int p,int q){
    return  find(id,p)==find(id,q);
}
//合并元素p和q所属的集合
void unionElements(int p,int q,int size,int id[]){
    int pID=find(id,p);
    int qID=find(id,q);
    if(pID==qID)return;
    for(int i=;i<size;i++){
        if(id[i]==pID){
            id[i]=qID;
        }
    }}
