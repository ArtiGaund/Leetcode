class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<nums.size()-1 and nums[low]<=nums[low+1]) low++;
        if(low==nums.size()-1) return 0;
        while(high>=0 and nums[high]>=nums[high-1]) high--;
        int submax=INT_MIN;
        int submin=INT_MAX;
        for(int i=low;i<=high;i++)
        {
            submax=max(submax,nums[i]);
            submin=min(submin,nums[i]);
        }
        while(low>0 and nums[low-1]>submin) low--;
        while(high<nums.size()-1 and nums[high+1]<submax) high++;
        return high-low+1;
    }
};