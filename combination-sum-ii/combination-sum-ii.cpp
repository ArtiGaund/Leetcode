class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return res;
    }
    void backtrack(vector<int> &v,int start,int target)
    {
        if(target==0)
        {
            res.push_back(sub);
            return;
        }
        if(target<0) return;
        for(int i=start;i<v.size();i++)
        {
            if(i>start and v[i]==v[i-1]) continue;
            sub.push_back(v[i]);
            backtrack(v,i+1,target-v[i]);
            sub.pop_back();
        }
    }
};