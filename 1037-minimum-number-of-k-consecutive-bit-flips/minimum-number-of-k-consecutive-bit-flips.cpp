class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int curFlips =0;
        int totalFlips =0;
        for(int i=0;i<nums.size();i++){
            if(i>=k and nums[i-k]==2){
                curFlips--;
            }
            if((curFlips%2) == nums[i]){
                if(i+k>nums.size()) return -1;
                nums[i]=2;
                curFlips++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};