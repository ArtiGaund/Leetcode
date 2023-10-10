class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int res=n;
        set<int> unique(nums.begin(),nums.end());
        vector<int> temp;;
        for(int a:unique)
            temp.push_back(a);
        int end=0;
        for(int start=0;start<temp.size();start++)
        {
            while(end<temp.size() and temp[end]<temp[start]+n) end++;
            int count=end-start;
            res=min(res,n-count);
        }
        return res;
    }
};