class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(cur,res,k,n,1);
        return res;
    }
    void backtrack(vector<int> &v,vector<vector<int>> &res,int k,int n,int begin)
    {
        if(k==0 and n==0)
        {
            res.push_back(v);
            return;
        }
        for(int i=begin;i<10 and i<=n;i++)
        {
            v.push_back(i);
            backtrack(v,res,k-1,n-i,i+1);
            v.pop_back();
        }
    }
};