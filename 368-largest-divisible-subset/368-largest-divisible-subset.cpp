class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};