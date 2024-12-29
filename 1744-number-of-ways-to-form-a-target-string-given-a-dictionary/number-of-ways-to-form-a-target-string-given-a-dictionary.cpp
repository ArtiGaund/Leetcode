class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLen=words[0].size();
        int targetLen=target.size();
        const int MOD = 1000000007;
        vector<vector<int>> charFreq(wordLen,vector<int>(26,0));
        for(string word:words){
            for(int j=0;j<wordLen;j++)
            charFreq[j][word[j]-'a']++;
        }
        vector<long> prev(targetLen+1,0);
        vector<long> cur(targetLen+1,0);
        prev[0]=1;
        for(int i=1;i<=wordLen;i++){
            cur=prev;
            for(int j=1;j<=targetLen;j++){
                int curPos=target[j-1]-'a';
                cur[j]+=(charFreq[i-1][curPos]*prev[j-1])%MOD;
                cur[j]%=MOD;
            }
            prev=cur;
        }
        return cur[targetLen];
    }
};