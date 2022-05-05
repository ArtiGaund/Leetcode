class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,count=0;
        for(int a:nums)
        {
            if(a==1) count++;
            else
            {
                res=max(res,count);
                count=0;
            }
        }
        res=max(res,count);
        return res;
    }
};