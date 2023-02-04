class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]<n and nums[i]!=nums[nums[i]])
                swap(nums[i],nums[nums[i]]);
            else i++;
        }
        for(i=0;i<n;i++)
            if(i!=nums[i]) return i;
        return n;
    }
};