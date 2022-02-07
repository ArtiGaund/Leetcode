class Solution {
public:
    //DFS
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {};
        vector<int> res, visited(n, 0); // 0: not visited; 1: in a dfs path; 2: visited
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, visited)) res.push_back(i);
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& visited) {
        if (visited[i] == 2) return true;
        if (visited[i] == 1) {
            return false;
        }
        visited[i] = 1;
        for (int j : graph[i]) {
            if (dfs(graph, j, visited) == false) return false;
        }
        visited[i] = 2;
        return true;
    }
};