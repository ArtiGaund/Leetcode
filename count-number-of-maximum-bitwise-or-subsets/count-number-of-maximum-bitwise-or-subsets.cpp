class Solution {
public:
    int res=1,max=0;
    int countMaxOrSubsets(vector<int>& nums) {
        backtrack(nums,0,0);
        return res;
    }
    void backtrack(vector<int> &nums,int cur,int start)
    {
        if(cur>max)
        {
            res=1;
            max=cur;
        }
        else if(cur==max) res+=1;
        for(int i=start;i<nums.size();i++)
            backtrack(nums,cur|nums[i],i+1);
    }
};