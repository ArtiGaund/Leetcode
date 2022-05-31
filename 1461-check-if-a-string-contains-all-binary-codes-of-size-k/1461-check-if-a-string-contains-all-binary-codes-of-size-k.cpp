class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=1<<k;
        vector<bool> got(need);
        int allone=need-1;
        int hashval=0;
        for(int i=0;i<s.size();i++)
        {
            hashval=((hashval<<1) & allone) | (s[i]-'0');
            if(i>=k-1 and !got[hashval])
            {
                got[hashval]=true;
                need--;
                if(need==0) return true;
            }
        }
        return false;
    }
};