class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0,sum=0,res=-1;
        for(;l<n;l++)
            sum+=nums[l];
        if(sum==x)
            res=l;
        l--;
        int r=n-1;
        for(;l>=0;l--)
        {
            sum-=nums[l];
            while(r>l&&sum<x)
            {
                sum+=nums[r];
                r--;
            }
            if(sum==x)
            {
                if(res==-1)
                    res=l+n-r-1;
                else
                    res=min(res,(l+n-r-1));
            }
        }
        return res;
    }
};