int merge(int arr[], int l, int r, int *temp)
{

    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    int res = merge(arr, l, mid, temp) + merge(arr, mid + 1, r, temp);

    int i = l, j = mid + 1;

    for (int k = l; k <= r; k++)
    {
        temp[k] = arr[k];
    }
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = temp[j];
            j++;
        }
        else if (j == r + 1 || temp[i] <= temp[j])
        {
            arr[k] = temp[i++];
        }
        else
        {
            arr[k] = temp[j++];
            res += mid - i + 1;
        }
    }
    return res;
}
int reversePairs(int *nums, int numsSize)
{
    int *temp = malloc(sizeof(int) * numsSize);

    return merge(nums, 0, numsSize - 1, temp);
}