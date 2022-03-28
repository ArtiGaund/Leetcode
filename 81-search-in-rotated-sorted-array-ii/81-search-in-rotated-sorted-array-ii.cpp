class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return false;
        int end=n-1,start=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return true;
            if(!isBinarySearch(nums,start,nums[mid]))
            {
                start++;
                continue;
            }
            bool pivot=existsInFirst(nums,start,nums[mid]);
            bool targetExist=existsInFirst(nums,start,target);
            if(pivot^targetExist)
            {
                 if(pivot) start=mid+1;
            else end=mid-1;
            }
           else
           {
               if(nums[mid]<target) start=mid+1;
               else end=mid-1;
           }
        }
        return false;
    }
    bool isBinarySearch(vector<int> &nums,int start,int ele)
    {
        return nums[start]!=ele;
    }
    bool existsInFirst(vector<int> &nums,int start,int ele)
    {
        return nums[start]<=ele;
    }
};