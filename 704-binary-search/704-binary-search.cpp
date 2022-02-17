class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        // if(nums.size()==0) return -1;
        // if(nums.size()==1 and nums[0]==target) return 0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
};