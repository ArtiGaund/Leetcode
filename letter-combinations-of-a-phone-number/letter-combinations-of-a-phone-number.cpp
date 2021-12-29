class Solution {
public:
    vector<string> res;
    unordered_map<char,string> mp;
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        if(digits.size()==0) return res;
        string s="";
        backtrack(digits,s,0);
        return res;
    }
    void backtrack(string s,string cur,int start)
    {
        if(cur.size()==s.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            char ch=s[i];
            for(int j=0;j<mp[ch].size();j++)
            {
                char temp=mp[ch][j];
                cur.push_back(temp);
                backtrack(s,cur,i+1);
                cur.pop_back();
            }
        }
    }
};