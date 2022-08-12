int search_two(int *arr, int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return search_two(arr, l, mid - 1, target);
    return search_two(arr, mid + 1, r, target);
}
int search(int *nums, int numsSize, int target)
{
    return search_two(nums, 0, numsSize - 1, target);
}