class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates,target,res,cur,0);
        return res;
    }
    void backtrack(vector<int> &nums,int target,vector<vector<int>> &res,vector<int> &cur,int start)
    {
        if(target==0)
        {
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        for(int i=start;i<nums.size();i++)
        {
            cur.push_back(nums[i]);
            backtrack(nums,target-nums[i],res,cur,i);
            cur.pop_back();
        }
    }
};