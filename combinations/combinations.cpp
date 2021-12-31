class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return res;
    }
    void backtrack(int start,int end,int k)
    {
        if(cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        for(int i=start;i<=end;i++)
        {
            cur.push_back(i);
            backtrack(i+1,end,k);
            cur.pop_back();
        }
    }
};