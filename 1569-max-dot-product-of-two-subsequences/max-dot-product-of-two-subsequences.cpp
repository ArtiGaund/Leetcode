class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax=INT_MIN;
        int firstMin=INT_MAX;
        int secondMax=INT_MIN;
        int secondMin=INT_MAX;
        for(int a:nums1){
            firstMax=max(firstMax,a);
            firstMin=min(firstMin,a);
        }
        for(int a:nums2){
            secondMax=max(secondMax,a);
            secondMin=min(secondMin,a);
        }
         if(firstMax<0 and secondMin>0) return firstMax*secondMin;
        if(firstMin>0 and secondMax<0) return firstMin*secondMax;
        int n=nums1.size(),m=nums2.size();
        vector<int> dp(m+1,0);
        vector<int> prevDp(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            dp=vector(m+1,0);
            for(int j=m-1;j>=0;j--)
            {
                int use=nums1[i]*nums2[j]+prevDp[j+1];
                dp[j]=max(use,max(prevDp[j],dp[j+1]));
            }
            prevDp=dp;
        }
        return dp[0];
    }
};