void ShellSort(*arr){
int len = sizeof(*arr) / sizeof(int);
    int h=len/2;
    wile(h>=1){
            for(int i=h;i<len;i+=h){
                int t=arr[i];
                int j;
                for(j=i;j-h>=0&&t<arr[j-h];j-=h){
                    arr[j]=arr[j-h];
                }
                arr[j]=t;
            }

        h/=2;
    }
}
