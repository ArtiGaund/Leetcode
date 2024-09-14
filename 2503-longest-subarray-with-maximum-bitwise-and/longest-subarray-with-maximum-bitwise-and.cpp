class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=0,res=0,count=0;
        for(int num:nums){
            if(maxVal<num){
                maxVal=num;
                res=count=0;
            }
            if(maxVal==num) count++;
            else count=0;
            res=max(res,count);
        }
        return res;
    }
};