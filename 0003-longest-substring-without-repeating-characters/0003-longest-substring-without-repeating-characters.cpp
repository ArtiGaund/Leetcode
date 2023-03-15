class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int start=0,maxlen=0;
        unordered_map<char,int> mp;
        for(int end=0;end<n;end++)
        {
            char right=s[end];
            if(mp.count(right)==1)
            {
                start=max(start,mp[right]+1);
            }
            mp[right]=end;
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};