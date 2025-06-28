class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        map<int,int> mp;
        for(int i=n-1;i>=n-k;i--)
            mp[v[i].second]=v[i].first;
        vector<int> res;
        for(auto it:mp)
            res.push_back(it.second);
        return res;
    }
};