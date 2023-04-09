class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<vector<int>> count(n,vector<int>(26));
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        int res=0,nodesSeen=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res=max(res,++count[node][colors[node]-'a']);
            nodesSeen++;
            for(auto nei:adj[node])
            {
                for(int i=0;i<26;i++)
                    count[nei][i]=max(count[nei][i],count[node][i]);
                indegree[nei]--;
                if(indegree[nei]==0)
                    q.push(nei);
            }
        }
        return nodesSeen<n?-1:res;
    }
};