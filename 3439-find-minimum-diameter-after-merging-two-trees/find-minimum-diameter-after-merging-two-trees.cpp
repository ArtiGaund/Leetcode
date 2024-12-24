class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adj1=buildAdjList(n,edges1);
        vector<vector<int>> adj2=buildAdjList(m,edges2);
        int dia1=findDiameter(n,adj1);
        int dia2=findDiameter(m,adj2);
        int combDia=ceil(dia1/2.0)+ceil(dia2/2.0)+1;
        return max({dia1,dia2,combDia});
    }
    vector<vector<int>> buildAdjList(int size,vector<vector<int>> &edges){
        vector<vector<int>> adj(size);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    int findDiameter(int n,vector<vector<int>> &adj){
        queue<int> q;
        vector<int> degrees(n);
        for(int node=0;node<n;node++){
            degrees[node]=adj[node].size();
            if(degrees[node]==1) q.push(node);
        }
        int remainingNodes=n;
        int leavesLayersRemoved=0;
        while(remainingNodes>2){
            int size=q.size();
            remainingNodes-=size;
            leavesLayersRemoved++;
            for(int i=0;i<size;i++){
                int curNode=q.front();
                q.pop();
                for(int nei:adj[curNode]){
                    degrees[nei]--;
                    if(degrees[nei]==1){
                        q.push(nei);
                    }
                }
            }
        }
        if(remainingNodes==2) return 2*leavesLayersRemoved+1;
        return 2*leavesLayersRemoved;
    }
};