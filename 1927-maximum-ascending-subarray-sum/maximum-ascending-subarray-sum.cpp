class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                res=max(res,sum);
                sum=0;
            } 
            sum+=nums[i];
        }
        return max(res,sum);
    }
};