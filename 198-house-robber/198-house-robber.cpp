class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int n1=0,n2=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=max(n1+nums[i],n2);
            n1=n2;
            n2=temp;
        }
        return n2;
    }
};