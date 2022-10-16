class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> res = new ArrayList<String>();
int pre=0;
for(int number:target){
    for(int i=0;i<number-pre-1;i++){
        res.add("Push");
        res.add("Pop");
    }
    res.add("Push");
    pre=number;
}
return res;
    }
}