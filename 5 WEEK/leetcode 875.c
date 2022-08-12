#define MAX(a, b) ((a) > (b) ? (a) : (b))
int getTime(int *piles, int mid, int pilesSize)
{
    int t = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        t += (piles[i] + mid - 1) / mid;
    }
    return t;
}
int minEatingSpeed(int *piles, int pilesSize, int h)
{
    int l = 1;
    int r = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        r = MAX(r, piles[i]);
    }
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (getTime(piles, mid, pilesSize) <= h)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}