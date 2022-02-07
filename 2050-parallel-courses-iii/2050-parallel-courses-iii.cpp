class Solution {
public:
    //BFS
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto r:relations)
        {
            adj[r[0]-1].push_back(r[1]-1);
            indegree[r[1]-1]++;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push({i,0});
        vector<int> cTime(n,0);
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int node=cur.first;
            int t=cur.second;
            int completeTime=t+time[node];
            cTime[node]=completeTime;
            for(auto it:adj[node])
            {
                cTime[it]=max(cTime[it],completeTime);
                indegree[it]--;
                if(indegree[it]==0) q.push({it,cTime[it]});
            }
        }
        int res=*max_element(cTime.begin(),cTime.end());
            return res;
    }
};