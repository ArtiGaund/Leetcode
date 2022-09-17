class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int odd=1,even=0;
        while(odd<n and even<n)
        {
            if(nums[odd]%2==1) odd+=2;
            else if(nums[even]%2==0) even+=2;
            else
            {
                swap(nums[odd],nums[even]);
                odd+=2;
                even+=2;
            }
        }
        return nums;
    }
};