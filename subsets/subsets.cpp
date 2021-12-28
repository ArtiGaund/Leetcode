class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int> &nums,int start)
    {
        res.push_back(sub);
        for(int i=start;i<nums.size();i++)
        {
            sub.push_back(nums[i]);
            backtrack(nums,i+1);
            sub.pop_back();
        }
    }
};