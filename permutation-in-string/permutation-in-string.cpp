class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
       int mp1[26]={0};
        for(char c:s1) mp1[c-'a']++;
        for(int i=0;i<=s2.size()-s1.size();i++)
        {
            int mp2[26]={0};
            for(int j=0;j<s1.size();j++)
                mp2[s2[i+j]-'a']++;
            if(matches(mp1,mp2)) return true;
        }
        return false;
    }
    bool matches(int mp1[],int mp2[])
    {
        for(int i=0;i<26;i++)
        {
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};