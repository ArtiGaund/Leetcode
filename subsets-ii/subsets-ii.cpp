class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int> &v,int start)
    {
        res.push_back(sub);
        for(int i=start;i<v.size();i++)
        {
            if(i>start and v[i]==v[i-1]) continue;
            sub.push_back(v[i]);
            backtrack(v,i+1);
            sub.pop_back();
        }
    }
};