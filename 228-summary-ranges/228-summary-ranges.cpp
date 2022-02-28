class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i=0,j=0;j<nums.size();j++)
        {
            if(j+1<nums.size() and nums[j+1]==nums[j]+1) continue;
            if(i==j)
                res.push_back(to_string(nums[i])+"");
            else
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            i=j+1;
        }
        return res;
    }
};