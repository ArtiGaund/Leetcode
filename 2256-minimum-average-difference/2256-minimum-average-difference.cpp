class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int minAvgDiff=numeric_limits<int>::max();
        long long curPrefixSum=0;
        long long totalSum=0;
        for(int a:nums) totalSum+=a;
        for(int i=0;i<n;i++)
        {
            curPrefixSum+=nums[i];
            long long left=curPrefixSum;
            left/=(i+1);
            long long right=totalSum-curPrefixSum;
            if(i!=n-1) right/=(n-i-1);
            int curDiff=int(abs(left-right));
            if(curDiff<minAvgDiff)
            {
                minAvgDiff=curDiff;
                ans=i;
            }
        }
        return ans;
    }
};