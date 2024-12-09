class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<bool> res(n,false);
        vector<int> prefix(nums.size(),0);
        prefix[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2) 
                prefix[i]=prefix[i-1]+1;
            else prefix[i]=prefix[i-1];
        }
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0],end=queries[i][1];
            res[i]=prefix[end]-prefix[start]==0;
        }
        return res;
    }
};