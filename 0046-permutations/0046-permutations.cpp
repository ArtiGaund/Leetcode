class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push(vector<int>());
        for(auto cur:nums)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                vector<int> old=q.front();
                q.pop();
                for(int j=0;j<=old.size();j++)
                {
                    vector<int> newPer(old);
                    newPer.insert(newPer.begin()+j,cur);
                    if(newPer.size()==nums.size()) res.push_back(newPer);
                    else q.push(newPer);
                }
            }
        }
        return res;
    }
};