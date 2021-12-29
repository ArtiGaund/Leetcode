class Solution {
public:
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s,0,res);
        return res;
    }
    void backtrack(string &s,int start,vector<string> &res,string temp="")
    {
        if(start==s.size())
        {
            res.push_back(temp);
            return;
        }
        backtrack(s,start+1,res,temp+s[start]);
        if(isupper(s[start]))
        {
           char c=tolower(s[start]);
            backtrack(s,start+1,res,temp+c);
        }
        else if(islower(s[start]))
        {
            char c=toupper(s[start]);
            backtrack(s,start+1,res,temp+c);
        }
    }
};