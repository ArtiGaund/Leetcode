class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int tail[n];
        tail[0]=nums[0];
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(tail[len-1]<nums[i]) tail[len++]=nums[i];
            else 
            {
                int c=ceilIndex(tail,0,len-1,nums[i]);
                tail[c]=nums[i];
            }
        }
        return len;
    }
    int ceilIndex(int tail[],int l,int h,int val)
    {
        while(l<h)
        {
            int m=(l+h)/2;
            if(tail[m]>=val) h=m;
            else l=m+1;
        }
        return h;
    }
};