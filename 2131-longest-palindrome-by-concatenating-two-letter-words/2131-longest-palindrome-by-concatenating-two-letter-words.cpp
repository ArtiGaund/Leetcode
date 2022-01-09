class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int unpaired=0;
        int ans=0;
        for(string w:words)
        {
            if(w[0]==w[1])
            {
                if(mp[w]>0)
                {
                    unpaired--;
                    mp[w]--;
                    ans+=4;
                }
                else
                {
                    mp[w]++;
                    unpaired++;
                }
            }
            else
            {
                string rev=w;
                reverse(rev.begin(),rev.end());
                if(mp[rev]>0)
                {
                    ans+=4;
                    mp[rev]--;
                }
                else mp[w]++;
            }
        }
        if(unpaired>0) ans+=2;
        return ans;
    }
};