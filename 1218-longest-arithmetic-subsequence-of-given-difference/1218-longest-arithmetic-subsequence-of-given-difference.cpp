class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int res=1;
        for(auto a:arr)
        {
            int beforeA=dp.count(a-difference)?dp[a-difference]:0;
            dp[a]=beforeA+1;
            res=max(res,dp[a]);
        }
        return res;
    }
};