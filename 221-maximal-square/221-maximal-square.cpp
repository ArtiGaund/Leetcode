class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> dp(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[j]=(matrix[i][j]=='1'?dp[j]+1:0);
            }
            maxArea=max(maxArea,findMaxArea(dp));
        }
        return maxArea;
    }
    int findMaxArea(vector<int> &dp)
    {
        int m=dp.size();
        stack<int> s;
        s.push(-1);
        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            while(s.top()!=-1 and dp[s.top()]>=dp[i])
            {
                int cur_h=dp[s.top()];
                s.pop();
                int cur_width=i-s.top()-1;
                int val=min(cur_h,cur_width);
                maxArea=max(maxArea,val*val);
            }
            s.push(i);
        }
        while(s.top()!=-1)
        {
            int cur_h=dp[s.top()];
            s.pop();
            int cur_width=m-s.top()-1;
            int val=min(cur_h,cur_width);
            maxArea=max(maxArea,val*val);
        }
        return maxArea;
    }
};