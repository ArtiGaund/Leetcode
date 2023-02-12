class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(target==nums[m]) return m;
            if(nums[s]<=nums[m])
            {
                if(nums[s]<=target and target<=nums[m])
                    e=m-1;
                else s=m+1;
            }
            else
            {
                if(nums[m]<=target and target<=nums[e])
                    s=m+1;
                else e=m-1;
            }
        }
        return -1;
    }
};