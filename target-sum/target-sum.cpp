class Solution {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        backtrack(nums,S,0,0);
        return ans;
    }
    void backtrack(vector<int> &nums,int target,int start,long long cur)
    {
            if(start==nums.size())
            {
                if(cur==target) ans++;
            }
            else
            {
                backtrack(nums,target,start+1,cur+nums[start]);
                backtrack(nums,target,start+1,cur-nums[start]);
            }
    }
};