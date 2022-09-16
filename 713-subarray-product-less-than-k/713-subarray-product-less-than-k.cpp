class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return k;
        int left=0,right=-1,prod=1,res=0;
        while(++right<n)
        {
            if(nums[right]>=k)
            {
                left=right+1;
                prod=1;
                continue;
            }
            prod*=nums[right];
            while(prod>=k)
                prod/=nums[left++];
            res+=right-left+1;
        }
        return res;
    }
};