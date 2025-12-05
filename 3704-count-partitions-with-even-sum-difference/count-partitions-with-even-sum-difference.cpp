class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int x:nums) sum+=x;
        return sum%2==0?nums.size()-1:0;
    }
};