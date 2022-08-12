//二分查找法前置条件是数组有序
//递归方式
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
//非递归方式
int serarch(int *arr, int target)
{
    int len = sizeof(arr) / sizeof(int);
    int l = 0, r = len - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}