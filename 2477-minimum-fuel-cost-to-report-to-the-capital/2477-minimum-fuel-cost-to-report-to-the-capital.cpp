class Solution {
public:
    long long bfs(int n,vector<int> adj[],vector<int> &degree,int &seats)
    {
        queue<int> q;
        for(int i=1;i<n;i++)
            if(degree[i]==1) q.push(i);
        vector<int> rep(n,1);
        long long fuel=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            fuel+=ceil((double)rep[node]/seats);
            for(auto ne:adj[node])
            {
                degree[ne]--;
                rep[ne]+=rep[node];
                if(degree[ne]==1 and ne!=0) q.push(ne);
            }
        }
        return fuel;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int> adj[n];
        vector<int> degree(n);
        for(auto r:roads)
        {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
            degree[r[0]]++;
            degree[r[1]]++;
        }
        return bfs(n,adj,degree,seats);
    }
};