class Solution {
public:
void bfs(int node,vector<int> &edges,vector<int> &dist){
    int n=edges.size();
    queue<int> q;
    q.push(node);
    vector<bool> vis(n,false);
    dist[node]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        int nei=edges[cur];
        if(nei!=-1 and !vis[nei]){
            dist[nei]=1+dist[cur];
            q.push(nei);
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,INT_MAX),dist2(n,INT_MAX);
        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);
        int minDistNode=-1,minDistTillNow=INT_MAX;
        for(int cur=0;cur<n;cur++){
            if(minDistTillNow>max(dist1[cur],dist2[cur])){
                minDistNode=cur;
                minDistTillNow=max(dist1[cur],dist2[cur]);
            }
        }
        return minDistNode;
    }
};