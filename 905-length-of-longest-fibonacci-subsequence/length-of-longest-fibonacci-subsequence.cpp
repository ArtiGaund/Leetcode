class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxLen=0;
        for(int cur=2;cur<n;cur++){
            int start=0;
            int end=cur-1;
            while(start<end){
                int pairSum=arr[start]+arr[end];
                if(pairSum>arr[cur]) end--;
                else if(pairSum<arr[cur]) start++;
                else{
                    dp[end][cur]=dp[start][end]+1;
                    maxLen=max(dp[end][cur],maxLen);
                    end--;
                    start++;
                }
            }
        }
        return maxLen==0?0:maxLen+2;
    }
};