class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<char> str;
        string temp="",res="";
        for(int i=0;i<s.size();i++)
        {
            int c=0;
            if(s[i]>='0' and s[i]<='9')
            {
                while(s[i]>='0' and s[i]<='9')
                {
                    c=c*10+s[i]-'0';
                    i++;
                }
                i--;
                num.push(c);
            }
            else if(s[i]=='[')
            {
                if(s[i-1]>='0' and s[i-1]<='9') str.push(s[i]);
                else
                {
                    str.push(s[i]);
                    num.push(1);
                }
            }
            else if(s[i]==']')
            {
                temp="";
                c=0;
                if(!num.empty())
                {
                    c=num.top();
                    num.pop();
                }
                while(!str.empty() and str.top()!='[')
                {
                    temp=str.top()+temp;
                    str.pop();
                }
                if(!str.empty() and str.top()=='[') str.pop();
                for(int j=0;j<c;j++)
                    res=temp+res;
                for(int j=0;j<res.size();j++)
                    str.push(res[j]);
                res="";
            }
            else str.push(s[i]);
        }
        while(!str.empty())
        {
            res=str.top()+res;
            str.pop();
        }
        return res;
    }
};