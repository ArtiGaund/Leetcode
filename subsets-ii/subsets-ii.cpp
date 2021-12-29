class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int> &nums,int start)
    {
        res.push_back(temp);
        for(int i=start;i<nums.size();i++)
        {
            if(i>start and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums,i+1);
            temp.pop_back();
        }
    }
};