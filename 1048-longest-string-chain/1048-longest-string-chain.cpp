class Solution {
public:
    static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    bool checkPossible(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int first=0,sec=0;
        while(first<s1.size())
        {
            if(s1[first]==s2[sec])
            {
                first++;
                sec++;
            }
            else first++;
        }
        if(first==s1.size() and sec==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkPossible(words[i],words[prev]) and dp[i]<dp[prev]+1)
                    dp[i]=dp[prev]+1;
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};