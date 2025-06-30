class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int end=0,maxLen=0;
        for(int start=0;start<nums.size();start++){
            while(nums[start]-nums[end]>1) end++;
            if(nums[start]-nums[end]==1)
                maxLen=max(maxLen,start-end+1);
        }
        return maxLen;
    }
};