class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(),nums.end());
        int maxDiff=(nums[1]-nums[0]);
        for(int i=2;i<nums.size();i++)
        {
            int diff=nums[i]-nums[i-1];
            maxDiff=max(maxDiff,diff);
        }
        return maxDiff;
    }
};