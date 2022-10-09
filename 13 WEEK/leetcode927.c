int minAddToMakeValid(char *s)
{
    int ans = 0;
    int leftCount = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            leftCount++;
        }
        else
        {
            if (leftCount > 0)
            {
                leftCount--;
            }
            else
            {
                ans++;
            }
        }
    }
    ans += leftCount;
    return ans;
}