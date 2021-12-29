class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return res;
    }
    void backtrack(vector<int> &nums,int target,int start)
    {
        if(target==0)
        {
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        for(int i=start;i<nums.size();i++)
        {
            if(i>start and nums[i]==nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(nums,target-nums[i],i+1);
            cur.pop_back();
        }
    }
};