class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int nextnondup=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[nextnondup-1]!=nums[i])
            {
                nums[nextnondup]=nums[i];
                nextnondup++;
            }
        }
        return nextnondup;
    }
};