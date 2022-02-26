class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=nums[0],maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cur=max(cur+nums[i],nums[i]);
            maxsum=max(maxsum,cur);
        }
        return maxsum;
    }
};