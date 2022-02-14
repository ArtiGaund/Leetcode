class Solution {
public:
    //kadane's
    int maxSubarraySumCircular(vector<int>& nums) {
       int total=0,curMin=0,minSum=nums[0],curMax=0,maxSum=nums[0];
        for(int a:nums)
        {
            curMin=min(curMin+a,a);
            minSum=min(minSum,curMin);
            curMax=max(curMax+a,a);
            maxSum=max(maxSum,curMax);
            total+=a;
        }
        return maxSum>0?max(maxSum,total-minSum):maxSum;
    }
};