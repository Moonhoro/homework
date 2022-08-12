#define MAX(a, b) ((a) > (b) ? (a) : (b))
int getTime(int mid, int r, int *weights, int weightsSize)
{
    int t = 1, i, sum = 0;
    for (int i = 0; i < weightsSize; i++)
    {
        if (sum + weights[i] > mid)
        {
            sum = 0;
            t++;
        }
        sum += weights[i];
    }

    return t;
}
int shipWithinDays(int *weights, int weightsSize, int days)
{
    int l = 0, r = 0;
    for (int i = 0; i < weightsSize; i++)
    {
        l = MAX(weights[i], l);
        r += weights[i];
    }
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (getTime(mid, r, weights, weightsSize) <= days)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}