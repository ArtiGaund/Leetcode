class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize=INT_MAX;
        int start=0;
        int sum=0;
        for(int end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            while(sum>=target)
            {
                minSize=min(minSize,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        if(minSize==INT_MAX) return 0;
        return minSize;
    }
};