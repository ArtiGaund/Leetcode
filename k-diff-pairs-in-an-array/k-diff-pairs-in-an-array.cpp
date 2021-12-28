class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       // using sliding window
        if(nums.size()<2) return 0;
        int res=0,begin=0,end=0;
        sort(nums.begin(),nums.end());
        while(begin<nums.size() and end<nums.size())
        {
            if(begin==end or nums[end]-nums[begin]<k) end++;
            else if(nums[end]-nums[begin]>k) begin++;
            else
            {
                res++;
                begin++;
                while(end<nums.size()-1 and nums[end]==nums[end+1]) end++;
                end++;
            }
        }
        return res;
    }
};