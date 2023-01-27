class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(),words.end());
        vector<string> res;
        for(string word:words)
        {
            int len=word.size();
            vector<bool> dp(len+1);
            dp[0]=true;
            for(int i=1;i<=len;i++)
            {
                for(int j=(i==len?1:0);!dp[i] and j<i;j++)
                {
                    dp[i]=(dp[j] and dict.count(word.substr(j,i-j)));
                }
            }
            if(dp[len]) res.push_back(word);
        }
        return res;
    }
};