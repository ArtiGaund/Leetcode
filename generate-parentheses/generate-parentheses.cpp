class Solution {
public:
    vector<string> res;
    string cur;
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        backtrack(open,close,n);
        return res;
    }
    void backtrack(int open,int close,int n)
    {
        if(open==n and close==n)
        {
            res.push_back(cur);
            return;
        }
        if(open<n)
        {
            cur.push_back('(');
            backtrack(open+1,close,n);
            cur.pop_back();
        }
        if(close<open)
        {
            cur.push_back(')');
            backtrack(open,close+1,n);
            cur.pop_back();
        }
    }
};