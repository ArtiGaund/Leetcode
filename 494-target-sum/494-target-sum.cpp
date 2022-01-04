class Solution {
public:
    int res=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        vector<int> sum(n);
        sum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            sum[i]=sum[i+1]+nums[i];
        dfs(nums,sum,target,0);
        return res;
    }
    void dfs(vector<int> &nums,vector<int> &sum,int target,int pos)
    {
        if(pos==nums.size())
        {
            if(target==0) res++;
            return;
        }
        if(sum[pos]<target) return;
        dfs(nums,sum,target-nums[pos],pos+1);
        dfs(nums,sum,target+nums[pos],pos+1);
    }
};