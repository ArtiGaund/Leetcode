class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur="";
        backtrack(res,cur,0,0,n);
        return res;
    }
    void backtrack(vector<string> &res,string cur,int open,int close,int max)
    {
        if(open==max and close==max)
        {
            res.push_back(cur);
            return;
        }
        if(open<max)
        {
            cur.push_back('(');
            backtrack(res,cur,open+1,close,max);
            cur.pop_back();
        }
        if(open>close)
        {
            cur.push_back(')');
            backtrack(res,cur,open,close+1,max);
            cur.pop_back();
        }
    }
};