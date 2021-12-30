class Solution {
public:
     vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(!(4<=s.size() and s.size()<=12)) return {};
       
        // vector<string> temp;
        backtrack(s,{},0);
        return res;
    }
    void backtrack(string s,vector<string> cur,int index)
    {
        //terminal condition
        if(cur.size()==4)
        {
            if(index==s.size())
            {
                string temp="";
                for(string s:cur)
                {
                    temp+=s;
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
            // no leading 
            if(num[0]=='0' and num.size()>1) break;
            if(stoi(num)>=0 and stoi(num)<256)
            {
                cur.push_back(num);
                backtrack(s,cur,i+1);
                cur.pop_back();
            }
        }
    }
};