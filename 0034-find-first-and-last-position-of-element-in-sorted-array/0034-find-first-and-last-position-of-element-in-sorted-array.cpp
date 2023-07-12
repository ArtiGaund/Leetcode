class Solution {
public:
    int search(vector<int> &nums,int target,bool findMaxIndex)
    {
        int low=0,high=nums.size()-1;
        int keyIndex=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target<nums[mid]) high=mid-1;
            else if(target>nums[mid]) low=mid+1;
            else
            {
                keyIndex=mid;
                if(findMaxIndex) low=mid+1;
                else high=mid-1;
            }
        }
        return keyIndex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        res[0]=search(nums,target,false);
        if(res[0]!=-1) res[1]=search(nums,target,true);
        return res;
    }
};