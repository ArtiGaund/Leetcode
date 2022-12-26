class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far_index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(far_index<i) return false;
            far_index=max(i+nums[i],far_index);
        }
        return true;
    }
};