class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0]*nums[1];
        int n=nums.size();
        int b=nums[n-1]*nums[n-2];
        return b-a;
    }
};