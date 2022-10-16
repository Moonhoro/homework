#define max(a,b) a>b?a:b
int maxChunksToSorted(int* arr, int arrSize){
int m=0,cnt=0;
for(int i=0;i<arrSize;i++){
m=max(m,arr[i]);
if(m==i){cnt++;}
}
return cnt;
}