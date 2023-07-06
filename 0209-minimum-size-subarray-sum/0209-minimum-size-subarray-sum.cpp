class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int minlen=INT_MAX;
        int start=0;
        for(int end=0;end<n;end++)
        {
            sum+=nums[end];
            while(sum>=target)
            {
                minlen=min(minlen,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};