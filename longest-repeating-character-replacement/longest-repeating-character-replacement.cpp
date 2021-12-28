class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int start=0,end=0,count=0,max_c=0;
        while(end<s.size())
        {
            mp[s[end]]++;
            if(count<mp[s[end]]) count=mp[s[end]];
            end++;
            while(!(end-start-count<=k))
            {
                if(mp[s[start]]==1) mp.erase(s[start]);
                else mp[s[start]]--;
                count=getMax(mp);
                start++;
            }
            max_c=max(max_c,end-start);
        }
        return max_c;
    }
    int getMax(unordered_map<char,int> &mp)
    {
        int res=0;
        for(auto it:mp)
            res=max(res,it.second);
        return res;
    }
};