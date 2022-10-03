class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (i + 1 < n && colors[i + 1] == colors[j])
                i++;

            if (j != i)
            {
                int mx = *max_element(neededTime.begin() + j, neededTime.begin() + i + 1);
                bool flag = false;
                for (int k = j; k <= i; k++)
                {
                    if (neededTime[k] != mx)
                        ans += neededTime[k];
                    else
                    {
                        if (flag)
                            ans += neededTime[k];
                        flag = true;
                    }
                }
            }
        }
        return ans;
    }
};