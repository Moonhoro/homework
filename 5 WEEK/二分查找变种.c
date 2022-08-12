// upper大于目标值的最小值
int upper(int *arr, int target)
{
    int len = sizeof(arr) / sizeof(int);
    int l = 0, r = len;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
// lower小于目标值的最大值
int lower(int *arr, int target)
{
    int len = sizeof(arr) / sizeof(int);
    int l = -1, r = len - 1;
    while (l < r)
    {
        //上取整防止相邻时陷入死循环
        int mid = l + (r - l + 1) / 2;
        if (arr[mid] < target)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

// ceil 如果存在返回最大索引 不存在返回upper
int ceil(int *arr, int target)
{
    int k = upper(arr, target);
    if (arr[k - 1] == target)
        return k - 1;
    else
        return k;
}
int lower_ceil(int *arr, int target)
{
    int u = upper(arr, target);
    int l = lower(arr, target);
    if (arr[l + 1] == target)
        return l;
    else
        return u;
}
//如果存在返回最大索引 不存在返回lower
int upper_floor(int *arr, int target)
{
    int u = upper(arr, target);
    int l = lower(arr, target);
    if (arr[u - 1] == target)
        return u - 1;
    else
        return l;
}
//如果存在返回最小索引 不存在返回lower
int lower_floor(int *arr, int target)
{
    int l = lower(arr, target);
    if (arr[l + 1] == target)
        return l + 1;
    else
        return l;
}