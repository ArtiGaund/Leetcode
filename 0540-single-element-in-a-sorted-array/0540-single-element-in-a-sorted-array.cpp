class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return  nums[0];
        int low=0,high=n-1;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[high]!=nums[high-1]) return nums[high];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]) return  nums[mid];
            else if((nums[mid]==nums[mid+1] and mid%2==0) or (nums[mid]==nums[mid-1] and mid%2!=0))
                low=mid+1;
            else high=mid-1;
        }
        return nums[low];
    }
};