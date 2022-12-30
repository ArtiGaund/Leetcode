class DisjointSet
{
    public:
    vector<int> size,parent;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int r,int c,int n)
    {
        return (r>=0 and r<n and c>=0 and c<n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        // step1:
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==0) continue;
                vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
                for(auto d:dir)
                {
                    int adjr=row+d.first;
                    int adjc=col+d.second;
                    if(isValid(adjr,adjc,n) and grid[adjr][adjc]==1)
                    {
                        int nodeNo=row*n+col;
                        int adjNo=adjr*n+adjc;
                        ds.unionset(nodeNo,adjNo);
                    }
                }
            }
        }
        //step 2:
        int mx=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1) continue;
                vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
                set<int> components;
                for(auto d:dir)
                {
                    int adjr=row+d.first;
                    int adjc=col+d.second;
                    if(isValid(adjr,adjc,n) and grid[adjr][adjc]==1)
                    {
                        components.insert(ds.findParent(adjr*n+adjc));
                    }
                }
                int sizeTotal=1;
                for(auto it:components)
                    sizeTotal+=ds.size[it];
                mx=max(mx,sizeTotal);
            }
        }
        for(int cell=0;cell<n*n;cell++)
            mx=max(mx,ds.size[ds.findParent(cell)]);
        return mx;
    }
};