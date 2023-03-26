class Solution {
public:
    int res=-1;
    void dfs(int node,vector<int> &edges,unordered_map<int,int> &dist,vector<bool> &vis)
    {
        vis[node]=true;
        int nei=edges[node];
        if(nei!=-1 and !vis[nei])
        {
            dist[nei]=dist[node]+1;
            dfs(nei,edges,dist,vis);
        }
        else if(nei!=-1 and dist.count(nei))
            res=max(res,dist[node]-dist[nei]+1);
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                unordered_map<int,int> dist;
                dist[i]=1;
                dfs(i,edges,dist,vis);
            }
        }
        return res;
    }
};