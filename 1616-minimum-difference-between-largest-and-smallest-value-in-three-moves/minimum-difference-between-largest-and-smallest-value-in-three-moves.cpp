class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size(),minDiff=INT_MAX;
        if(n<=4) return 0;
        partial_sort(nums.begin(),nums.begin()+4,nums.end());
        nth_element(nums.begin()+4,nums.begin()+(n-4),nums.end());
        sort(nums.begin(),nums.end());
        for(int left=0,right=n-4;left<4;left++,right++){
            minDiff=min(minDiff,nums[right]-nums[left]);
        }
        return minDiff;
    }
};