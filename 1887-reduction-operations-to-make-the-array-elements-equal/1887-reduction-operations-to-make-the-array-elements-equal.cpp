class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0,up=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) up++;
            res+=up;
        }
        return res;
    }
};