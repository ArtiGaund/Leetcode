class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res=0;
        unordered_map<int,int> mp;
        int start=0;
        for(int end=0;end<nums.size();end++)
        {
            k-=mp[nums[end]]++;
            while(k<=0)
            {
                k+=(--mp[nums[start++]]);
            }
            res+=start;
        }
        return res;
    }
};