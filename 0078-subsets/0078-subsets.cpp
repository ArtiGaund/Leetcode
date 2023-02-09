class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());
        for(int cur:nums)
        {
            int n=subsets.size();
            for(int i=0;i<n;i++)
            {
                vector<int> set(subsets[i]);
                set.push_back(cur);
                subsets.push_back(set);
            }
        }
        return subsets;
    }
};