class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        sort(strs.begin(),strs.end());
        int min=strs[0].size();
        for(int i=1;i<strs.size();i++)
            if(min>strs[i].size())
                min=strs[i].size();
        string res="";
        for(int i=0;i<min;i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(i<strs[j].size()&&i<strs[j-1].size()&&strs[j][i]==strs[j-1][i])
                {
                    if(j==strs.size()-1)
                        res+=strs[j-1][i];
                }
                else
                    return res;
            }
        }
        return res;
    }
};