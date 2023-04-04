class Solution {
public:
    static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),comp);
        int res=1;
        for(int i=0;i<n;i++)
        {
            dp[words[i]]=1;
            int maxPosSubChain=0;
            for(int j=0;j<words[i].size();j++)
            {
                string predecessor=words[i].substr(0,j)+words[i].substr(j+1);
                if(dp.find(predecessor)!=dp.end())
                    maxPosSubChain=max(maxPosSubChain,dp[predecessor]);
            }
            dp[words[i]]+=maxPosSubChain;
            res=max(res,dp[words[i]]);
        }
        return res;
    }
};