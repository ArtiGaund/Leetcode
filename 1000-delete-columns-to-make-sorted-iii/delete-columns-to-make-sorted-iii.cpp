class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs[0].size();
        vector<int> dp(m,1);
        for(int i=m-1;i>=0;i--){
            for(int j=i+1;j<m;j++){
                bool bad=false;
                for(string str:strs){
                    if(str[i]>str[j]){
                        bad=true;
                        break;
                    }
                }
                if(bad) continue;
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int kept=0;
        for(int x: dp){
            kept=max(kept,x);
        }
        return m-kept;
    }
};