class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]!=i+1)
            {
                if(nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
                else return nums[i];
            }
            else i++;
        }
        return -1;
    }
};