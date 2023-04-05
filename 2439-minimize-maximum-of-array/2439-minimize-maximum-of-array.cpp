class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res=0,prefixSum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            res=max(res,(prefixSum+i)/(i+1));
        }
        return res;
    }
};