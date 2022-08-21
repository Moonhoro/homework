//采用数组的方式实现堆
//返回父亲索引
int parent(int i){
    if(i!=0)return (i-1)/2;
}
//返回左孩子索引
int leftChild(int i){
    return i*2+1;
}
int rightChild(int i){
    return  i*2+2;
}
void  swap(int i,int j,int *arr){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}
int SiftUp(int *arr,int k){
    while(k>0&&arr[parent(k)]<arr[k]){
        swap(k, parent(k),arr);
        k= parent(k);
    }
}
void SiftDown(int *arr,int k){
    while (){
        int j= leftChild(k);
        if(arr[j+1]>arr[j]){
            j= rightChild(k);
        }
        if(arr[k]>=arr[j])break;
        else swap(k,j,arr);
    }
}
//向堆中添加元素
void  add(int *arr,int e){
    len = sizeof(arr)/sizeof(arr[0]);
    arr[len]=e;
    SiftUp(arr,len);
}
//取出堆中最大元素
int findMax(int *arr){
    return arr[0];
}
//取出最大元素
int extractMax(int *arr){
    int ret= findMax(arr);
    len = sizeof(arr)/sizeof(arr[0]);
    swap(0,len-1,arr);
    arr[len]=0;
    SiftDown(int *arr,0);
    return ret;
}
//取出最大值替换成元素e
int replace(int *arr,int e){
    int ret= findMax(arr);
    swap(0,e,arr);
    SiftDown(arr,0);
    return ret;
}
//将数组转换为堆
void Array(int *arr){
    len = sizeof(arr)/sizeof(arr[0]);
    for(int i= len-1;i>=0;i--){
        SiftDown(arr,i)
    }
}
//原地堆排序
void sort(int *arr){
    len = sizeof(arr)/sizeof(arr[0]);
    for (int i=(len-2)/2;i>=0;i--){
        SiftDown(arr,i);
    }

}