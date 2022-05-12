class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        backtrack(nums,res,cur,mp);
        return res;
    }
    void backtrack(vector<int> &nums,vector<vector<int>> &res,vector<int> &cur,unordered_map<int,int> &mp)
    {
        if(cur.size()==nums.size())
        {
            res.push_back(cur);
            return;
        }
        for(auto &[val,freq]:mp)
        {
            if(freq==0) continue;
            freq--;
            cur.push_back(val);
            backtrack(nums,res,cur,mp);
            cur.pop_back();
            freq++;
        }
    }
};