class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lower_bound(nums,upper+1)-lower_bound(nums,lower);
    }
    long long lower_bound(vector<int> &nums,int val){
        int left=0,right=nums.size()-1;
        long long res=0;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum<val){
                res+=(right-left);
                left++;
            }else right--;
        }
        return res;
    }
};