class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;
        int all=(1<<n)-1;
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> vis;
        for(int i=0;i<n;i++)
        {
            int mask=(1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int val=cur.first;
            int dis=cur.second.first;
            int mask=cur.second.second;
            for(auto temp:graph[val])
            {
                int newmask=(mask|(1<<temp));
                if(newmask==all) return dis+1;
                else if(vis.count({temp,newmask}))
                    continue;
                vis.insert({temp,newmask});
                q.push({temp,{dis+1,newmask}});
            }
        }
        return 0;
    }
};