class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int unpaired=0; // to count word who don't have mirror or have same letter
        int ans=0;
        for(string w:words)
        {
            if(w[0]==w[1]) // word size is 2 and both letter are same
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
        if(unpaired>0) ans+=2; //if have unpaired word add one to the ans
        return ans;
    }
};