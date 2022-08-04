class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++) graph[arr[i]].push_back(i);
        queue<int> q;
        vector<bool> vis(n);
        q.push(0);
        vis[0]=1;
        int step=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int node=q.front();
                q.pop();
               if(node+1<n and !vis[node+1]){
                    if(node+1==n-1) return step;
                    q.push(node+1);
                    vis[node+1]=true;
                }
                if(node-1>=0 and !vis[node-1]){
                    if(node-1==n-1) return step;
                    q.push(node-1);
                    vis[node-1]=true;
                }

                for(auto i:graph[arr[node]])
                {
                    if(i==node or vis[i]) continue;
                    if(i==n-1) return step;
                    q.push(i);
                    vis[i]=1;
                }
                graph[arr[node]].clear();
            }
            step++;
        }
        return -1;
    }
};