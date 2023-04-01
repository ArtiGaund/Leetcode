class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int> dp(n+1,false);
        dp[n]=true;
        for(int index=n-1;index>=0;index--)
        {
            for(int i=index;i<n;i++)
            {
                string cur=s.substr(index,i-index+1);
                if(dict.find(cur)!=dict.end() and dp[i+1])
                {
                    dp[index]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};