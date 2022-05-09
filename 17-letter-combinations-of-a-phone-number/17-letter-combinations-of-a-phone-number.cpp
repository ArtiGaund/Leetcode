class Solution {
public:
    vector<string> res;
    map<char,string> mp;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string cur="";
        backtrack(digits,cur,0);
        return res;
    }
    void backtrack(string digits,string cur,int index)
    {
        if(cur.size()==digits.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=index;i<digits.size();i++)
        {
            char c=digits[i];
            for(int j=0;j<mp[c].size();j++)
            {
                char temp=mp[c][j];
                cur.push_back(temp);
                backtrack(digits,cur,i+1);
                cur.pop_back();
            }
        }
    }
};