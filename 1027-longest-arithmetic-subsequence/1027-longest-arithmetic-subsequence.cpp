class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        unordered_map<int,int> dp[n+1];
        int maxlen=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                int cnt=1;
                if(dp[j].count(diff))
                    cnt=dp[j][diff];
                dp[i][diff]=1+cnt;
                maxlen=max(maxlen,dp[i][diff]);
            }
        }
        return maxlen;
    }
};