class Solution {
public:
    bool solve(int index,string s,set<string> &dict,vector<int> &dp)
    {
        if(index==s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<s.size();i++)
        {
            string cur=s.substr(index,i-index+1);
            if(dict.find(cur)!=dict.end() and solve(i+1,s,dict,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(0,s,dict,dp);
    }
};