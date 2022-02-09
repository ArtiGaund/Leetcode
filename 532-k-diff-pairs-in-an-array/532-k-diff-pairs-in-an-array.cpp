class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       if(nums.size()<2) return 0;
        int res=0,start=0,end=0;
        sort(nums.begin(),nums.end());
        while(start<nums.size() and end<nums.size())
        {
            if(start==end or nums[end]-nums[start]<k) end++;
            else if(nums[end]-nums[start]>k) start++;
            else
            {
                res++;
                start++;
                while(end<nums.size()-1 and nums[end]==nums[end+1]) end++;
                end++;
            }
        }
        return res;
    }
};