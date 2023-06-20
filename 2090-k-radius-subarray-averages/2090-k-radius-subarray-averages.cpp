class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n=nums.size();
        vector<int> average(n,-1);
        if(2*k+1>n) return average;
        long long windowSum=0;
        for(int i=0;i<(2*k+1);i++)
            windowSum+=nums[i];
        average[k]=windowSum/(2*k+1);
        for(int i=(2*k+1);i<n;i++)
        {
            windowSum=windowSum-nums[i-(2*k+1)]+nums[i];
            average[i-k]=windowSum/(2*k+1);
        }
        return average;
    }
};