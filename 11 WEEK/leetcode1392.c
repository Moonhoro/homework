_Bool equal(char *text, int l1, int l2, int r1, int r2)
{
    for (int i = l1, j = r1; i <= l2 && j <= r2; i++, j++)
        if (text[i] != text[j])
            return false;
    return true;
}
char *longestPrefix(char *s)
{
    for (int len = strlen(s) - 1; len >= 1; len--)
    {
        if (equal(s, 0, len - 1, strlen(s) - len, strlen(s) - 1))
        {
            s[len] = NULL;
            return s;
        }
    }
    return "";
}