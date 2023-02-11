class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        res[0]=search(nums,target,false);
        if(res[0]!=-1)
            res[1]=search(nums,target,true);
        return res;
    }
    int search(vector<int> &nums,int target,bool findMaxIndex)
    {
        int keyIndex=-1;
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<nums[mid]) end=mid-1;
            else if(target>nums[mid]) start=mid+1;
            else
            {
                keyIndex=mid;
                if(findMaxIndex) start=mid+1;
                else end=mid-1;
            }
        }
        return keyIndex;
    }
};