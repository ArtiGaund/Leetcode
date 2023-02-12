class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int a:nums) res=res^a;
        return res;
    }
};