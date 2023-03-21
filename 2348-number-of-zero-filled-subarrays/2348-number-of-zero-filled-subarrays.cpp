class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0,numSubArr=0;
        for(auto n:nums)
        {
            if(n==0) numSubArr++;
            else numSubArr=0;
            res+=numSubArr;
        }
        return res;
    }
};