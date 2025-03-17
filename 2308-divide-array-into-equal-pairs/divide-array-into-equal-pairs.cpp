class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2==1) return false;
        unordered_map<int,int> mp;
        for(int num:nums) mp[num]++;
        for(auto it:mp){
            if(it.second%2==1) return false;
        }
        return true;
    }
};