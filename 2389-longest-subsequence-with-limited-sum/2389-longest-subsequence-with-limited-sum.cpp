class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        vector<int> res;
        for(auto q:queries)
        {
             int index = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            res.push_back(index);
        }
        return res;
    }
};