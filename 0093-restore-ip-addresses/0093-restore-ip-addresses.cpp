class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(!(4<=s.size() and s.size()<=12)) return res;
        backtrack(s,{},0);
        return res;
    }
    void backtrack(string s,vector<string> cur,int index)
    {
        if(cur.size()==4)
        {
            if(index==s.size())
            {
                string temp="";
                for(string str:cur)
                {
                    temp+=str;
                    temp+=".";
                }
                temp.pop_back();
                res.push_back(temp);
            }
            return;
        }
        string num="";
        int n;
        if(index+3>s.size()) n=s.size();
        else n=index+3;
        for(int i=index;i<n;i++)
        {
            num+=s[i];
            if(num[0]=='0' and num.size()>1) break;
            if(0<=stoi(num) and stoi(num)<=255)
            {
                cur.push_back(num);
                backtrack(s,cur,i+1);
                cur.pop_back();
            }
        }
    }
};