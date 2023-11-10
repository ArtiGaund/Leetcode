class Solution {
public:
    unordered_map<int,vector<int>> graph;
    void dfs(int node,int prev,vector<int> &res){
        res.push_back(node);
        for(auto nei:graph[node]){
            if(nei!=prev)
                dfs(nei,node,res);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        for(auto e:adjPairs){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int root=0;
        for(auto &p:graph){
            if(p.second.size()==1){
                root=p.first;
                break;
            }
        }
        vector<int> res;
        dfs(root,INT_MAX,res);
        return res;
    }
};