class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1000000007;
        stack<int> st;
        int n=arr.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            if(st.size()>0)
            {
                int prevSmall=st.top();
                dp[i]=dp[prevSmall]+(i-prevSmall)*arr[i];
            }
            else
                dp[i]=(i+1)*arr[i];
            st.push(i);
        }
        long sum=0;
        for(int count:dp)
        {
            sum+=count;
            sum=sum%mod;
        }
        return (int)sum;
    }
};