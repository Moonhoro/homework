class Solution {
    public String mergeAlternately(String word1, String word2) {
int m=word1.length(),n=word2.length();
int i=0,j=0;
StringBuilder res=new StringBuilder();
while(i<m||j<n){
    if(i<m){
        res.append(word1.charAt(i));
        i++;
    }
     if(j<n){
        res.append(word2.charAt(j));
        j++;
    }
}
return res.toString();
    }
}