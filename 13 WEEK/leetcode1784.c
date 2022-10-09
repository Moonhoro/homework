bool checkOnesSegment(char *s)
{
    int flag2 = 0;
    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == '0')
        {
            flag2 = 1;
        }
        if (s[i] == '1' && flag2 == 1)
            return false;
    }
    return true;
}