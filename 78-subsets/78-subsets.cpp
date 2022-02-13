class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int> &nums,int index)
    {
        res.push_back(cur);
        for(int i=index;i<nums.size();i++)
        {
            cur.push_back(nums[i]);
            backtrack(nums,i+1);
            cur.pop_back();
        }
    }
};