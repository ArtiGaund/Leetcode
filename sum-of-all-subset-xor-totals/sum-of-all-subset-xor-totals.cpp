class Solution {
public:
    int res=0;
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums,0,0);
        return res;
    }
    void backtrack(vector<int> &nums,int start,int sum)
    {
        if(start==nums.size())
        {
            res+=sum;
            return;
        }
        backtrack(nums,start+1,sum);
        sum^=nums[start];
        backtrack(nums,start+1,sum);
        return;
    }
};