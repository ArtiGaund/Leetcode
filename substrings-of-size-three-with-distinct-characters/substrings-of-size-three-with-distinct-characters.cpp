class Solution {
public:
    int countGoodSubstrings(string s) {
        int len=s.size();
        int count=0,max_c=0,k=3;
        unordered_map<char,int> mp;
        for(int i=0;i<k;i++) mp[s[i]]++;
        count=mp.size();
        if(count==k) max_c++;
        for(int i=k;i<len;i++)
        {
            mp[s[i]]++;
            if(mp.find(s[i-k])!=mp.end())
            {
                if(mp[s[i-k]]==1) mp.erase(s[i-k]);
                else mp[s[i-k]]--;
            }
            count=mp.size();
            if(count==k) max_c++;
        }
        return max_c;
    }
};