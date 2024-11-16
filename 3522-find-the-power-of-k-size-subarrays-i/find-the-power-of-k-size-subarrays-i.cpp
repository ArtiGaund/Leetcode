class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int> res(n-k+1,-1);
        int consecutiveCount=1;
        for(int index=0;index<n-1;index++){
            if(nums[index]+1==nums[index+1]){
                consecutiveCount++;
            }else consecutiveCount=1;
            if(consecutiveCount>=k) res[index-k+2]=nums[index+1];
        }
        return res;
    }
};