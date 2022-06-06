class Solution {
public:
    int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int index=i;index<=j;index++)
        {
            int cost=(nums[i-1]*nums[index]*nums[j+1])+solve(nums,i,index-1,dp)+solve(nums,index+1,j,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,1,n,dp);
    }
};