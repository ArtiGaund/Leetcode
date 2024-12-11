class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        int maxBeauty=0,maxVal=0;
        for(int num:nums) maxVal=max(maxVal,num);
        vector<int> count(maxVal+1,0);
        for(int num:nums){
            count[max(num-k,0)]++;
            if(num+k+1<=maxVal) count[num+k+1]--;
        }
        int curSum=0;
        for(int val:count){
            curSum+=val;
            maxBeauty=max(maxBeauty,curSum);
        }
        return maxBeauty;
    }
};