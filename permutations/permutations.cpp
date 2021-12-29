class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> used;
        backtrack(nums,res,cur,used);
        return res;
    }
    void backtrack(vector<int> &nums,vector<vector<int>>& res,vector<int> &cur,unordered_set<int> &used)
    {
        if(cur.size()==nums.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!used.count(nums[i]))
            {
                cur.push_back(nums[i]);
                used.insert(nums[i]);
                backtrack(nums,res,cur,used);
                cur.pop_back();
                used.erase(nums[i]);
            }
        }
    }
};