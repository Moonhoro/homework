int numDifferentIntegers(char *word)
{
    int i = 0, j;
    int a[60] = {0};
    int s;
    int cunt = 0;
    while (word[i])
    {
        s = 0;
        while (word[i] >= 'a' && word[i] <= 'z')
            i++; //删英语字符
        if (word[i] == '\0')
            break;
        while (word[i] >= '0' && word[i] <= '9') //读完数字
        {
            s = s * 10 + word[i] - 48;
            s %= 1000000; //防止越界
            i++;
        }
        for (j = 0; j < cunt; j++) //检查是否已经存在
        {
            if (a[j] == s)
                break;
        }
        if (j >= cunt)
        {
            a[cunt] = s;
            cunt++;
        }
    }
    return cunt;
}