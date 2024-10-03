class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int totalSum=0;
        for(int a:nums) totalSum=(totalSum+a)%p;
        int target=totalSum%p;
        if(target==0) return 0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int curSum=0,minLen=n;
        for(int i=0;i<n;i++){
            curSum=(curSum+nums[i])%p;
            int needed=(curSum-target+p)%p;
            if(mp.find(needed)!=mp.end()) minLen=min(minLen,i-mp[needed]);
            mp[curSum]=i;
        }
        return minLen==n?-1:minLen;
    }
};