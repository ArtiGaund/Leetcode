class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixsum=0;
        int longestsubarray=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            if(prefixsum==k)
                longestsubarray=i+1;
            if(mp.find(prefixsum-k)!=mp.end())
                longestsubarray=max(longestsubarray,i-mp[prefixsum-k]);
            if(mp.find(prefixsum)==mp.end())
                mp[prefixsum]=i;
        }
        return longestsubarray;
    }
};