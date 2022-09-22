class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ') temp+=s[i];
            else
            {
                reverse(temp.begin(),temp.end());
                res+=temp;
                res+=" ";
                temp="";
            }
        }
        if(temp.size()!=0) 
        {
            reverse(temp.begin(),temp.end());
            res+=temp;
        }
        return res;
    }
};