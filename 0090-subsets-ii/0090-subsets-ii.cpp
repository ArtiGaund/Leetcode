class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int start=0,end=0;
        for(int i=0;i<nums.size();i++)
        {
            start=0;
            if(i>0 and nums[i]==nums[i-1]) start=end+1;
            end=res.size()-1;
            for(int j=start;j<=end;j++)
            {
                vector<int> set(res[j]);
                set.push_back(nums[i]);
                res.push_back(set);
            }
        }
        return res;
    }
};