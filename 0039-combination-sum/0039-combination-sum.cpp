class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void solve(vector<int> &nums,int index,int target)
    {
        if(target==0)
        {
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        for(int i=index;i<nums.size();i++)
        {
            cur.push_back(nums[i]);
            solve(nums,i,target-nums[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,0,target);
        return res;
    }
};