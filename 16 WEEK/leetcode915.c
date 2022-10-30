#define MAX(a, b) ((a) > (b) ? (a) : (b))

int partitionDisjoint(int* nums, int numsSize) {
    int leftMax = nums[0], leftPos = 0, curMax = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        curMax = MAX(curMax, nums[i]);
        if (nums[i] < leftMax) {
            leftMax = curMax;
            leftPos = i;
        }
    }
    return leftPos + 1;
}