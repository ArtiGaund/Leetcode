class Solution {
public:
   vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0);
        return res;
    }
    void backtrack(vector<int> &nums,int target,int index)
    {
        if(target==0)
        {
            res.push_back(cur);
            return;
        }
        if(target<0)  return;
        for(int i=index;i<nums.size();i++)
        {
            cur.push_back(nums[i]);
            backtrack(nums,target-nums[i],i);
            cur.pop_back();
        }
    }
};