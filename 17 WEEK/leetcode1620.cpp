
class Solution
{
public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
    {
        int max = -1;
        vector<int> ans = {-1, -1};
        for (int i = 0; i <= 50; i++)
        {
            for (int j = 0; j <= 50; j++)
            {
                int cur = 0;
                for (int k = 0; k < towers.size(); k++)
                {
                    int d2 = pow(i - towers[k][0], 2) + pow(j - towers[k][1], 2);
                    if (d2 <= radius * radius)
                        cur += towers[k][2] / (1 + sqrt(d2));
                }
                if (cur > max)
                {
                    max = cur;
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
};