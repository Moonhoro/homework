void swap(int *arr,int i,int j){
    int k=arr[i];
    arr[i]=arr[j];
    arr[j]=k;
}
//冒泡排序法
void BubbleSort(int *arr) {
    int len = sizeof(*arr) / sizeof(int);
    for (int i = 0; i < len;) {
        int lastSwappedIndex = 0;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                lastSwappedIndex=j+1;
            }
            if(lastSwappedIndex==0)break;
            i=len-lastSwappedIndex;
        }
    }
}