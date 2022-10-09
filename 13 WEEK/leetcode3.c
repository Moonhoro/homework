#define max(a, b) a > b ? a : b
int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int table[128] = {0};
    int cnt = 0;
    int res = 0, i = 0, j = 0;
    while (i < len)
    {
        if (table[s[i]] == 0)
        {
            table[s[i]] = 1;
            cnt++;
            i++;
            res = max(cnt, res);
        }
        else
        {
            res = max(cnt, res);
            table[s[j]]--;
            j++;
            cnt--;
        }
    }
    return res;
}