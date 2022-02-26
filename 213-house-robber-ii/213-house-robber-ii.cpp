class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int res1=solve(nums,0,n-2);
        int res2=solve(nums,1,n-1);
        return max(res1,res2);
    }
    int solve(vector<int> nums,int s,int e)
    {
        int prev=0,cur=0;
        for(int i=s;i<=e;i++)
        {
            int temp=max(prev+nums[i],cur);
            prev=cur;
            cur=temp;
        }
        return cur;
    }
};