//插入排序法
int InsertionSort(int arr[],int l,int r){
	for(int i=l;i<r;i++){
		for(int j=i;j-1>=l;j--){
			if(arr[j]<arr[j-1]){
					int k;
					k=arr[j];
					arr[j]=arr[j-1];	
					arr[j-1]=k;}
			else break;
}
}
}
//取最小值
int min(int a,int b){
return a>b?b:a;
}
//自底向上归并排序
sortBU(int arr[]){
int *temp=(int *)malloc(sizeof(arr));
memcpy(temp, arr, sizeof(arr));
int len=sizeof(arr)/sizeof(int);
//插入排序法优化
for(int i = 0; i < len; i += 16)
        InsertionSort.sort(arr, i,min(i + 15, n - 1));
for(int sz=16;sz<len;sz+=sz){
for(int i=0;i+sz<len;i+=sz+sz){
//如果arr[i+sz-1]<arr[i+saz]则本来就为有序 无需再次排序
if(arr[i+sz-1]>arr[i+saz]){
merge(arr,i,min(i+sz+sz-1,n-1),i+sz-1);
}
}
}
}

void merge(int arr[],int l,int r,int mid)
{
int *temp=(int *)malloc(sizeof(arr));
memcpy(temp, arr, sizeof(arr));
int i=l,j=mid+1;
for(int k=l;k<=r;k++)
{
if(i>mid){arr[k]=temp[j-l];j++;}
else if(j>r){arr[k]=temp[i-l];i++;}
else if(temp[i-l]<=temp[j-l]){arr[k]=temp[i-l];i++;}
else{arr[k]=temp[j-l];j++;}
}
}