1) BFS:- same as topological sort the only difference
i) for reachable node we can mark direct neighbor, but for undirected node
ii) if we reach any "node", then we can reach its all neighbor
iii) x->y and y->z then also x->z
iv) if(vis[x][y]==true and y->z) then vis[x][z]=true;
same as topo sort but also include bool vis[n][n];
for(auto p:pre) vis[p[0]][p[1]]=true;
same
while(!q.empty())
{
//same
for(auto it:adj[node])
{
for(int i=0;i<n;i++)
if(vis[i][node]) vis[i][it]=true;
//same
}
vector<bool> res;
for(auto q:queries) res.pb(vis[q[0]][q[1]]);
}
2) DFS
void dfs(int src,vector<int> adj[],vector<vector<bool>> &ispre,vector<bool> &vis,int node)
{
vis[node]=true;
ispre[src][node]=true;
for(auto it:adj[node])
{
if(!vis[it])
dfs(src,adj,ispre,vis,it);
}
}