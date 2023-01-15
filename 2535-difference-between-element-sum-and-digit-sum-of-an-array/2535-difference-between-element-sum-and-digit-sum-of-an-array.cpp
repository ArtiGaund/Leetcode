class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum=0;
        for(int a:nums) eleSum+=a;
        int digitSum=0;
        for(int a:nums)
        {
            while(a>0)
            {
                digitSum+=(a%10);
                a=a/10;
            }
        }
        int res=abs(eleSum-digitSum);
        return res;
    }
};