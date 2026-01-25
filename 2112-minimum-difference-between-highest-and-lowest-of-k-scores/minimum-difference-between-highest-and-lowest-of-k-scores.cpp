class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i+k-1<n;i++){
            res=min(res,nums[i+k-1]-nums[i]);
        }
        return res;
    }
};