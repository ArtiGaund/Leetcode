class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long,int> preSumMp;
        long long sum=0;
        int count=0;;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k) count++;
            long long rem=sum-k;
            if(preSumMp.find(rem)!=preSumMp.end())
            {
                count+=preSumMp[rem];
            }
           preSumMp[sum]++;
        }
        return count;
    }
};