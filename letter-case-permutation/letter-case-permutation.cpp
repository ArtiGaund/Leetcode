class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        string cur="";
        backtrack(s,0,cur);
        return res;
    }
    void backtrack(string s,int index,string cur)
    {
        if(index==s.size())
        {
            res.push_back(cur);
            return;
        }
        backtrack(s,index+1,cur+s[index]);
        if(islower(s[index]))
        {
            char c=toupper(s[index]);
            backtrack(s,index+1,cur+c);
        }
        if(isupper(s[index]))
        {
            char c=tolower(s[index]);
            backtrack(s,index+1,cur+c);
        }
    }
};