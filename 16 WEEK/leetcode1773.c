int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
int index,res=0;
if(strcmp(ruleKey,"type")==0)index=0;
if(strcmp(ruleKey,"color")==0)index=1;
if(strcmp(ruleKey,"name")==0)index=2;
for(int i=0;i<itemsSize;i++)
{
    if(strcmp(items[i][index],ruleValue)==0)res++;

}
return res;
}