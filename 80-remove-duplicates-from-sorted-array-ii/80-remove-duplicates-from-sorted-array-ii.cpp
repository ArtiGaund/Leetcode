class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size();
        if(n==0) return 0;
        if(n<3) return n;
        int i=1,j=2;
        while(j<n)
        {
            if(nums[j]==nums[i] and nums[j]==nums[i-1]) j++;
            else
            {
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
        return i+1;
    }
};