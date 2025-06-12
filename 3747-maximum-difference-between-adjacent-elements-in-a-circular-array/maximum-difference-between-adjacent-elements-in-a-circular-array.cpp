class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int diff=abs(nums[0]-nums[n-1]);
        for(int i=1;i<n;i++)
            diff=max(diff,abs(nums[i-1]-nums[i]));
        return diff;
    }
};