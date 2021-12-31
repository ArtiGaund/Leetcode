class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,1);
        return res;
    }
    void backtrack(int k,int target,int index)
    {
        if(target==0)
        {
            if(cur.size()==k) 
                res.push_back(cur);
            return;
        }
        for(int i=index;i<=9;i++)
        {
            cur.push_back(i);
            backtrack(k,target-i,i+1);
            cur.pop_back();
        }
    }
};