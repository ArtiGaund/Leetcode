class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int index=0;
        for(int i=0;i<n;i++)
            if(nums[i]%2==0) res[index++]=nums[i];
        for(int i=0;i<n;i++)
            if(nums[i]%2==1) res[index++]=nums[i];
        return res;
    }
};