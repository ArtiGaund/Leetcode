class Solution {
public:
    string simplifyPath(string path) {
        string res="/";
        stack<string> s;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]!='/')
            {
                string temp="";
                while(path[i]!='/' and i<path.size())
                {
                    temp+=path[i];
                    i++;
                }
                if(temp=="..")
                {
                    if(!s.empty()) s.pop();
                }
                else
                {
                    string t=".";
                    if(temp!=t) s.push(temp);
                }
            }
        }
        if(s.empty()) return res;
        while(!s.empty())
        {
            res=s.top()+res;
            s.pop();
            res="/"+res;
        }
        res.pop_back();
        return res;
    }
};