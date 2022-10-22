int find(int *N,int x){
    if(N[x]!=x)return find(N,N[x]);
    return N[x];
}
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
int N[5100];
for(int i=0;i<5100;i++){N[i]=i;}
for(int i=0;i<dislikesSize;i++){
    int a=dislikes[i][0],b=dislikes[i][1];
    if(find(N,a)==find(N,b))return false;
N[find(N,a)]=find(N,b+n);
N[find(N,b)]=find(N,a+n);
}
return true;
}