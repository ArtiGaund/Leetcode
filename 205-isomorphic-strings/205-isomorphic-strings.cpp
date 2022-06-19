class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> mp1(256,-1),mp2(256,-1);
        for(int i=0;i<s.size();i++)
        {
            char c1=s[i];
            char c2=t[i];
            if(mp1[c1]==-1 and mp2[c2]==-1)
            {
                mp1[c1]=c2;
                mp2[c2]=c1;
            }
            else if(!(mp1[c1]==c2 and mp2[c2]==c1)) return false;
        }
        return true;
    }
};