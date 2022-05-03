class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         int n=nums.size();
        int s=0,e=n-1,i,max_i,min_i;
        for(s=0;s<n-1;s++)
        {
            if(nums[s]>nums[s+1])
                break;
        }
        if(s==n-1)
            return 0;
        for(e=n-1;e>0;e--)
        {
            if(nums[e]<nums[e-1])
                break;
        }
        max_i=nums[s];
        min_i=nums[s];
        for(i=s+1;i<=e;i++)
        {
            if(nums[i]<min_i)
                min_i=nums[i];
            if(nums[i]>max_i)
                max_i=nums[i];
        }
        for(i=0;i<s;i++)
        {
            if(nums[i]>min_i)
            {
                s=i;
                break;
            }
        }
        for(i=n-1;i>=e+1;i--)
        {
            if(nums[i]<max_i)
            {
                e=i;
                break;
            }
        }
        return (e-s+1);
    }
};