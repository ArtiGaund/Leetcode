class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rightSum=0;
        for(int a:nums) rightSum+=a;
        int count=0;
        long long leftSum=0;
        for(int i=0;i<nums.size()-1;i++){
            leftSum+=nums[i];
            rightSum-=nums[i];
            if(leftSum>=rightSum) count++;
        }
        return count;
    }
};