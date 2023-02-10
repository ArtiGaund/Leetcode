class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        if(s=="") return res;
        res.push_back(s);
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                int n=res.size();
                for(int j=0;j<n;j++)
                {
                    vector<char> temp(res[j].begin(),res[j].end());
                    if(islower(temp[i])) temp[i]=toupper(temp[i]);
                    else temp[i]=tolower(temp[i]);
                    res.push_back(string(temp.begin(),temp.end()));
                }
            }
        }
        return res;
    }
};