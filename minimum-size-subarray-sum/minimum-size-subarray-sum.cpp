class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int min_size=INT_MAX,start=0;
        // unordered_map<int,int> mp;
        int sum=0;
        for(int end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            while(sum>=target)
            {
                min_size=min(min_size,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        if(min_size==INT_MAX) return 0;
        return min_size;
    }
};