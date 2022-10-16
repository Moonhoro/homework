#define min(a,b) a<b?a:b
int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size){
int a=0,b=1;
for(int i=1;i<nums1Size;i++){
 int at = a, bt = b;
 a=nums1Size;
 b=nums1Size;
    if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1])
{
   a=at;
   b=bt+1;
}
if(nums1[i]>nums2[i-1]&&nums2[i]>nums1[i-1]){
    a=min(bt,a);
    b=min(at+1,b);
}
}
return min(a,b);
}