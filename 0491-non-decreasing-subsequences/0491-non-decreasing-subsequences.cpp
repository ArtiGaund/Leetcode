class Solution {
public:
    void backtrack(vector<int> &nums,vector<int> &temp,set<vector<int>> &res,int index)
    {
        int n=nums.size();
        if(index>=n)
        {
            if(temp.size()>=2) res.insert(temp);
            return;
        }
        if(!temp.size() or nums[index]>=temp.back())
        {
            temp.push_back(nums[index]);
            backtrack(nums,temp,res,index+1);
            temp.pop_back();
        }
        backtrack(nums,temp,res,index+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> res;
        backtrack(nums,temp,res,0);
        return vector(res.begin(),res.end());
    }
};