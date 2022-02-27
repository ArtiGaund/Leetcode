class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> dp(m,0);
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dp[j]=(mat[i][j]=='1'?dp[j]+1:0);
            maxarea=max(maxarea,findmaxarea(dp));
        }
        return maxarea;
    }
    int findmaxarea(vector<int> &dp)
    {
        int m=dp.size();
        stack<int> s;
        s.push(-1);
        int maxarea=0;
        for(int i=0;i<m;i++)
        {
            while(s.top()!=-1 and dp[s.top()]>=dp[i])
            {
                int cur_h=dp[s.top()];
                s.pop();
                int cur_w=i-s.top()-1;
                int val=min(cur_h,cur_w);
                maxarea=max(maxarea,val*val);
            }
            s.push(i);
        }
        while(s.top()!=-1)
            {
                int cur_h=dp[s.top()];
                s.pop();
                int cur_w=m-s.top()-1;
                int val=min(cur_h,cur_w);
                maxarea=max(maxarea,val*val);
            }
        return maxarea;
    }
};