class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        vector<int> res;
        for(auto it:mp){
            if(it.second==1) res.push_back(it.first);
        }
        return res;
    }
};