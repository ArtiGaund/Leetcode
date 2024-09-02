class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long> prefixSum(n);
        prefixSum[0]=chalk[0];
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+chalk[i];
        long sum=prefixSum[n-1];
        int remainingChalk=k%sum;
        return binarySearch(prefixSum,remainingChalk);
    }
    int binarySearch(vector<long> &nums,long target){
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target) low=mid+1;
            else high=mid;
        }
        return high;
    }
};