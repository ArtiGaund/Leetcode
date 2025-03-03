class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        int less=0,greater=nums.size()-1;
        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--){
            if(nums[i]<pivot){
                res[less]=nums[i];
                less++;
            }
            if(nums[j]>pivot){
                res[greater]=nums[j];
                greater--;
            }
        }
        while(less<=greater){
            res[less]=pivot;
            less++;
        }
        return res;
    }
};