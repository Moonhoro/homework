# KMP算法

```
//next算法
int Getnext(char ch[],int length,int next[]){
next[i]=0;
while(i<=length){
if(j==0||ch[i]==ch[j])next[++i]=++j;
else j=next[j];
}
}
```
