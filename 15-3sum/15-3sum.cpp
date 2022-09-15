class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i-1]==nums[i]) continue;
            searchPair(nums,-nums[i],i+1);
        }
        return res;
    }
    void searchPair(vector<int> &nums,int target,int left)
    {
        int right=nums.size()-1;
        while(left<right)
        {
            int cursum=nums[left]+nums[right];
            if(cursum==target)
            {
                res.push_back({-target,nums[left],nums[right]});
                left++;
                right--;
                while(left<right and nums[left]==nums[left-1])
                    left++;
                while(left<right and nums[right]==nums[right+1])
                    right--;
            }
            else if(target>cursum) left++;
            else right--;
        }
    }
};