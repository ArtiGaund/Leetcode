class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int count=0;
        unordered_set<int> vis;
        for(int vertex=0;vertex<n;vertex++){
            if(vis.count(vertex)) continue;
            int compInfo[2]={0,0};
            dfs(vertex,graph,vis,compInfo);
            if(compInfo[0]*(compInfo[0]-1)==compInfo[1]) count++;
        }
        return count;
    }
    void dfs(int cur,vector<vector<int>> &graph,unordered_set<int> &vis,int compInfo[2]){
        vis.insert(cur);
        compInfo[0]++;
        compInfo[1]+=graph[cur].size();
        for(int next:graph[cur]){
            if(!vis.count(next)){
                dfs(next,graph,vis,compInfo);
            }
        }
    }
};