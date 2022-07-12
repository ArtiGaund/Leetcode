class Solution {
public:
    bool solve(int index,int size,vector<int> &nums,vector<int> &dp)
    {
        if(index==nums.size())
            return (dp[0]==dp[1] and dp[1]==dp[2] and dp[2]==dp[3]);
        for(int i=0;i<4;i++)
        {
            if(dp[i]+nums[index]>size) continue;
            int j=i;
            while(--j>=0)
                if(dp[i]==dp[j]) break;
            if(j!=-1) continue;
            dp[i]+=nums[index];
            if(solve(index+1,size,nums,dp)) return true;
            dp[i]-=nums[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int a:matchsticks) sum+=a;
        if(sum==0 or sum%4) return false;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        vector<int> dp(4,0);
        return solve(0,sum/4,matchsticks,dp);
    }
};