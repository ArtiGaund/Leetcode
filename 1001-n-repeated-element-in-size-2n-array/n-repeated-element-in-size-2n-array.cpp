class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        for(auto it:mp){
            if(it.second == n) return it.first;
        }
        return 0;
    }
};