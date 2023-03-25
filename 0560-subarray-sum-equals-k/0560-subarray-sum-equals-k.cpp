class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k) count++;
            int rem=sum-k;
            if(mp.find(rem)!=mp.end())
                count+=mp[rem];
            mp[sum]++;
        }
        return count;
    }
};