class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        vector<int> res;
        for(const auto [n,cnt]:mp)
        {
            if(cnt==1 and mp.count(n+1)==0 and mp.count(n-1)==0)
                res.push_back(n);
        }
        return res;
    }
};