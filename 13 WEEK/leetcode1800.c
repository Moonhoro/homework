#define max(a, b) a > b ? a : b
int maxAscendingSum(int *nums, int numsSize)
{
    int sum = nums[0];
    int res = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
            sum += nums[i];
        else
        {
            res = max(res, sum);
            sum = nums[i];
        }
    }
    res = max(res, sum);
    return res;
}