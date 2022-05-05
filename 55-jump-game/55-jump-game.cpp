class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest_index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(farthest_index<i) return false;
            farthest_index=max(i+nums[i],farthest_index);
        }
        return true;
    }
};