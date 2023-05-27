class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n=stone.size();
        vector<int> dp(4);
        for(int i=n-1;i>=0;i--)
        {
            dp[i%4]=stone[i]-dp[(i+1)%4];
            if(i+2<=n)
                dp[i%4]=max(dp[i%4],stone[i]+stone[i+1]-dp[(i+2)%4]);
            if(i+3<=n)
                dp[i%4]=max(dp[i%4],stone[i]+stone[i+1]+stone[i+2]-dp[(i+3)%4]);
        }
        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";
    }
};