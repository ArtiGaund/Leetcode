class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a:nums) mp[a]++;
        for(auto it:mp)
            if(it.second==1) return it.first;
        return -1;
    }
};