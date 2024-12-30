class Solution {
public:
int mod=1000000007;
int dfs(vector<int> &dp,int end,int zero,int one){
    if(dp[end]!=-1) return dp[end];
    int count=0;
    if(end>=one) count+=dfs(dp,end-one,zero,one);
    if(end>=zero) count+=dfs(dp,end-zero,zero,one);
    dp[end]=count%mod;
    return dp[end];
}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        dp[0]=1;
        int res=0;
        for(int end=low;end<=high;end++){
            res+=dfs(dp,end,zero,one);
            res%=mod;
        }
        return res;
    }
};