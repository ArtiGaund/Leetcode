class Solution {
public:
    vector<vector<int>> v;
    vector<int> temp;
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums,0);
        int res=0;
        for(int i=0;i<v.size();i++)
        {
            int sum=0;
            for(int j=0;j<v[i].size();j++)
                sum^=v[i][j];
            res+=sum;
        }
        return res;
    }
    void backtrack(vector<int> &nums,int start)
    {
        if(start==nums.size())
        {
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[start]);
        backtrack(nums,start+1);
        temp.pop_back();
        backtrack(nums,start+1);
    }
};