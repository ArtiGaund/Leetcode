class Solution {
public:
    unordered_map<string,vector<int>> mp;
    vector<int> diffWaysToCompute(string str) {
        if(mp.find(str)!=mp.end()) return mp[str];
        vector<int> res;
        if(str.find("+")==string::npos and str.find("-")==string::npos and str.find("*")==string::npos) res.push_back(stoi(str));
        else
        {
            for(int i=0;i<str.size();i++)
            {
                char ch=str[i];
                if(!isdigit(ch))
                {
                    vector<int> left=diffWaysToCompute(str.substr(0,i));
                    vector<int> right=diffWaysToCompute(str.substr(i+1));
                    for(auto p1:left)
                    {
                        for(auto p2:right)
                        {
                            if(ch=='+') res.push_back(p1+p2);
                            else if(ch=='-') res.push_back(p1-p2);
                            else if(ch=='*') res.push_back(p1*p2);
                        }
                    }
                }
            }
        }
        mp[str]=res;
        return res;
    }
};