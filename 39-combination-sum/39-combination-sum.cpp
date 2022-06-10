class Solution {
public:
    void solve(int index,vector<int> &nums,int target,vector<vector<int>> &res,vector<int> &cur)
    {
        if(index==nums.size())
        {
            if(target==0)
                res.push_back(cur);
            return;
        }
        if(nums[index]<=target)
        {
            cur.push_back(nums[index]);
            solve(index,nums,target-nums[index],res,cur);
            cur.pop_back();
        }
        solve(index+1,nums,target,res,cur);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(0,candidates,target,res,cur);
        return res;
    }
};