int bruteforce(char *s,char *t){
    if(strlen(s)< strlen(t))return -1;
    for(int i=0;i+ strlen(t)-1< strlen(s);i++){
        int j=0;
        for(;j< strlen(t);j++){
            if(s[i+j]!=t[j])break;
        }
        if(j==strlen(t))return i;
    }
    return  -1;
}