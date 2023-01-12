class Solution {
public:
    void flip(int i,int j,vector<vector<int>> &mat)
    {
        int m=mat.size(),n=mat[0].size();
        mat[i][j]^=1;
        if(i-1>=0) mat[i-1][j]^=1;
        if(i+1<m) mat[i+1][j]^=1;
        if(j-1>=0) mat[i][j-1]^=1;
        if(j+1<n) mat[i][j+1]^=1;
    }
    bool all_zeros(vector<vector<int>> &mat)
    {
        int sum=0;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                sum+=mat[i][j];
        return sum==0;
    }
    int minFlips(vector<vector<int>>& mat) {
        if(all_zeros(mat)) return 0;
        map<vector<vector<int>>,int> mp;
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> vis;
        mp[mat]=0;
        q.push(mat);
        vis.insert(mat);
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            auto adj=cur;
            for(int i=0;i<adj.size();i++)
            {
                for(int j=0;j<adj[0].size();j++)
                {
                    flip(i,j,adj);
                    if(all_zeros(adj)) return mp[cur]+1;
                    if(vis.find(adj)==vis.end())
                    {
                        vis.insert(adj);
                        mp[adj]=mp[cur]+1;
                        q.push(adj);
                    }
                    flip(i,j,adj);
                }
            }
        }
        return -1;
    }
};