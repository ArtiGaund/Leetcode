class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> graph[n];
        for(auto p:pre)
            graph[p[0]].push_back(p[1]);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
            for(auto it:graph[i])
                indegree[it]++;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:graph[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return topo.size()==n;
    }
};