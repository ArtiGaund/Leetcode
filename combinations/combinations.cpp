class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(1,n,k,res,cur);
        return res;
    }
    void backtrack(int start,int last,int k,vector<vector<int>> &res,vector<int> &cur)
    {
        if(cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        for(int i=start;i<=last;i++)
        {
            cur.push_back(i);
            backtrack(i+1,last,k,res,cur);
            cur.pop_back();
        }
    }
};