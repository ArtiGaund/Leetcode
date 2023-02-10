class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        vector<char> cur(2*n);
        solve(n,0,0,cur,0);
        return res;
    }
    void solve(int n,int open,int close,vector<char> &cur,int index)
    {
        if(open==n and close==n) res.push_back(string(cur.begin(),cur.end()));
        else
        {
            if(open<n)
            {
                cur[index]='(';
                solve(n,open+1,close,cur,index+1);
            }
            if(open>close)
            {
                cur[index]=')';
                solve(n,open,close+1,cur,index+1);
            }
        }
    }
};