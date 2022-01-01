class Solution {
public:
    int res=0;
    int countArrangement(int n) {
        vector<bool> vis(n+1,false);
        backtrack(n,1,vis);
        return res;
    }
    void backtrack(int n,int pos,vector<bool> &vis)
    {
        if(pos>n) res++;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] and (pos%i==0 or i%pos==0))
            {
                vis[i]=true;
                backtrack(n,pos+1,vis);
                vis[i]=false;
            }
        }
    }
};