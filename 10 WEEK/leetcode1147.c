
_Bool equal(char *text,int l1,int l2,int r1,int r2){
    for(int i=l1,j=r1;i<=l2&&j<=r2;i++,j++)
        if(text[i]!=text[j])return false;
    return true;
}
int solve(char *text,int l,int r){
    if(l>r)return 0;
    for(int i=l,j=r;i<j;i++,j--){
        if(equal(text,l,i,j,r))
            return 2+solve(text,i+1,j-1);
    }
    return 1;
}
int longestDecomposition(char * text){
    int r=strlen(text);
    return solve(text,0,r-1);
}