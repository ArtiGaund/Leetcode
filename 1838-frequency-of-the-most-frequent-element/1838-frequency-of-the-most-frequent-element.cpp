class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        long cur=0;
        for(int right=0;right<nums.size();right++){
            long target=nums[right];
            cur+=target;
            if((right-left+1)*target-cur>k){
                cur-=nums[left];
                left++;
            }
        }
        return nums.size()-left;
    }
};