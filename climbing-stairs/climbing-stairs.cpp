class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return n;
        vector<int> res(n+1,-1);
        return solve(n,res);
    }
    int solve(int n,vector<int> &res)
    {
        if(res[n]==-1)
        {
            if(n==1) res[n]=1;
            else if(n==2) res[n]=2;
            else res[n]=solve(n-1,res)+solve(n-2,res);
        }
        return res[n];
    }
};