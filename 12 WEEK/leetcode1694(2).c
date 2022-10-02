char *reformatNumber(char *number)
{
    int len = 0;
    for (int j = 0; j < strlen(number); j++)
    {
        if (isdigit(number[j]))
            len++;
    }
    char *res = malloc(sizeof(char) * 200);
    int k = 0, flag = 0;
    for (int i = 0; i < strlen(number); i++)
    {

        if (isdigit(number[i]))
        {
            if (flag == 3)
            {
                res[k++] = '-';
                flag = 0;
            }
            res[k] = number[i];
            k++;
            flag++;
        }
    }
    int pre = k - 2;
    if (res[pre] == '-')
    {
        char tmp_ch = res[pre - 1];
        res[pre - 1] = '-';
        res[pre] = tmp_ch;
    }
    res[k] = '\0';
    return res;
}