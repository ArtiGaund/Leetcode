class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int res=-1,premin=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>premin){
                res=max(res,nums[i]-premin);
            }else premin=nums[i];
        }
        return res;
    }
};