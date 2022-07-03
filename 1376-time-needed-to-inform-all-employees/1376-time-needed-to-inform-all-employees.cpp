class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inf) {
        vector<int> graph[n];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]==-1) continue;
            graph[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(headID);
        vector<int> time(n,0);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(!graph[cur].size()) continue;
            for(auto it:graph[cur])
            {
                q.push(it);
                time[it]=time[cur]+inf[cur];
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,time[i]);
        return res;
    }
};