class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<abs(target) or (sum+target)%2==1) return 0;
        return targetSum(nums,(sum+target)/2);
    }
    int targetSum(vector<int> &v,int sum){
        int n=v.size();
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int a:v){
            for(int j=sum;j>=a;j--)
                dp[j]+=dp[j-a];
        }
        return dp[sum];
    }
};