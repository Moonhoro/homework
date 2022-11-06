class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int n = sequence.size(), m = word.size();
        if (n < m)
            return 0;
        vector<int> f(n);
        for (int i = m - 1; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (sequence[i - m + j + 1] != word[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
        }
        return *max_element(f.begin(), f.end());
    }
};