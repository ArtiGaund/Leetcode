class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       int n1=0,n2=nums[0],temp;
        for(int i=1;i<n;i++)
        {
            temp=max(n1+nums[i],n2);
            n1=n2;
            n2=temp;
        }
        return n2;
    }
   
};