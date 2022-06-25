class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=1,n=nums.size();
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[i-1])
            {
                if(c==0)
                    return 0;
                if(i==1||nums[i]>=nums[i-2])
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
                --c;
            }
        }
        return true;
    }
};