class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        solve(nums,0,cur);
        return res;
    }
    void solve(vector<int> &nums,int index,vector<int> &cur)
    {
        if(index==nums.size()) res.push_back(cur);
        else
        {
            for(int i=0;i<=cur.size();i++)
            {
                vector<int> newPer(cur);
                newPer.insert(newPer.begin()+i,nums[index]);
                solve(nums,index+1,newPer);
            }
        }
    }
};