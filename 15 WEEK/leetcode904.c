#define max(a, b) a > (b) ? a : b
int totalFruit(int *fruits, int fruitsSize)
{
    int table[100000] = {0};
    int sum = 0;
    int res = 0;
    for (int i = 0, j = 0; i < fruitsSize; i++)
    {
        if (table[fruits[i]] == 0)
        {
            sum++;
        }
        table[fruits[i]]++;
        while (sum > 2)
        {
            table[fruits[j]]--;
            if (table[fruits[j]] == 0)
                sum--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    return res;
}