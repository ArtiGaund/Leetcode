class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
            return;
        int i=n-2;
        while(i>=0&&nums[i+1]<=nums[i])
            i--;
        int j=n-1;
        while(i>=0&&j!=i)
        {
            if(nums[j]>nums[i])
            {
                swap(nums[i],nums[j]);
                break;
            }
            else
                j--;
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};