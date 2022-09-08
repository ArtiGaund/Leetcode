class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        for(auto it:mp)
        {
            if(it.second>1) return true;
        }
        return false;
    }
};