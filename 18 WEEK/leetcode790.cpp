class Solution
{
public:
    int numTilings(int n)
    {
        if (n <= 2)
            return n;
        vector<long long> f(n + 1);
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            f[i] = 2 * f[i - 1] + f[i - 3];
            f[i] %= static_cast<long long>(1e9 + 7);
        }
        return f[n];
    }
};