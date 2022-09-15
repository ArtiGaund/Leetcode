class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nextele=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[nextele]=nums[i];
                nextele++;
            }
        }
        return nextele;
    }
};