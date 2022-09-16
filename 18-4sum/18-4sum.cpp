class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                searchPair(nums,target,i,j);
            }
        }
        return res;
    }
    void searchPair(vector<int> &nums,int target,int first,int second)
    {
        int left=second+1;
        int right=nums.size()-1;
        while(left<right)
        {
            long long int cursum=(long)nums[first]+(long)nums[second]+(long)nums[left]+(long)nums[right];
            if(cursum==target)
            {
                res.push_back({nums[first],nums[second],nums[left],nums[right]});
                left++;
                right--;
                while(left<right and nums[left]==nums[left-1]) left++;
                while(left<right and nums[right]==nums[right+1]) right--;
            }
            else if(cursum<target) left++;
            else right--;
        }
    }
};