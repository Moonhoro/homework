int atMostNGivenDigitSet(char **digits, int digitsSize, int n)
{
    int re = 0;
    int len = 0;
    int i, j;
    for (i = n; i; i /= 10, len++)
        ;
    int num[len];
    char cn[len + 1];
    sprintf(cn, "%d", n);
    num[0] = 1;
    for (i = 1, j = digitsSize; i < len; i++)
    {
        re += j;
        num[i] = j;
        j *= digitsSize;
    }
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < digitsSize; j++)
        {
            if (digits[j][0] >= cn[i])
            {
                break;
            }
        }
        re += num[len - i - 1] * j;
        if (j == digitsSize || digits[j][0] > cn[i])
        {
            break;
        }
    }
    if (i == len)
    {
        re++;
    }
    return re;
}