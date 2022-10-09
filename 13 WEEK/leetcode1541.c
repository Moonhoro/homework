int minInsertions(char *s)
{
    int res = 0;
    int need = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            need = need + 2;
            if (need % 2 == 1)
            {
                res++;
                need--;
            }
        }
        if (s[i] == ')')
        {
            need--;
            if (need == -1)
            {
                res++;
                need = 1;
            }
        }
    }
    return res + need;
}