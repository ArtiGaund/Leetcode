class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string temp="";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ') temp+=s[i];
            else
            {
                if(!temp.empty())
                {
                    reverse(temp.begin(),temp.end());
                    res+=temp;
                    res+=" ";
                    temp="";
                }
            }
        }
        if(!temp.empty())
        {
            reverse(temp.begin(),temp.end());
            res+=temp;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};