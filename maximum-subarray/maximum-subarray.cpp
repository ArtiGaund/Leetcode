class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_far=nums[0],max_end=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(max_end+nums[i]<nums[i]) max_end=nums[i];
            else max_end+=nums[i];
            if(max_end>max_far) max_far=max_end;
        }
        return max_far;
    }
};