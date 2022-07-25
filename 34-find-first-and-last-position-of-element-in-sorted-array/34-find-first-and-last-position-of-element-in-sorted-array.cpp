class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {
        int first=findBound(nums,target,true);
        if(first==-1) return {-1,-1};
        int last=findBound(nums,target,false);
        return {first,last};
    }
    int findBound(vector<int> &nums,int target,bool isfirst)
    {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                if(isfirst)
                {
                    if(mid==low or nums[mid-1]!=target)// we found the lower bound
                        return mid;
                    high=mid-1;
                }
                else
                {
                    if(mid==high or nums[mid+1]!=target) //we found the upper bound
                        return mid;
                    low=mid+1;
                }
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};