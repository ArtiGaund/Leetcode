class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum=INT_MIN;
        int start=0,end=nums.size()-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            maxSum=max(maxSum,sum);
            start++;
            end--;
        }
        return maxSum;
    }
};