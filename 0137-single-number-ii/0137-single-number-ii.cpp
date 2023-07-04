class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(auto a:nums)
        {
            ones=ones^(a&~twos);
            twos=twos^(a&~ones);
        }
        return ones;
    }
};