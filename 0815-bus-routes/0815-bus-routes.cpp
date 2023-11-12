class Solution {
public:
    vector<int> adj[501];
    void createGraph(vector<vector<int>> &routes){
        for(int i=0;i<routes.size();i++){
            for(int j=i+1;j<routes.size();j++){
                if(haveCommonNode(routes[i],routes[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    bool haveCommonNode(vector<int> &route1,vector<int> &route2){
        int i=0,j=0;
        while(i<route1.size() and j<route2.size()){
            if(route1[i]==route2[j]) return true;
            route1[i]<route2[j]? i++ : j++;
        }
        return false;
    }
    void addStartingNodes(queue<int> &q,vector<vector<int>> &routes,int source){
        for(int i=0;i<routes.size();i++){
            if(isStopExist(routes[i],source)) q.push(i);
        }
    }
    bool isStopExist(vector<int> &route,int stop){
        for(int j=0;j<route.size();j++){
            if(route[j]==stop) return true;
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        for(int i=0;i<routes.size();i++)
            sort(routes[i].begin(),routes[i].end());
        createGraph(routes);
        queue<int> q;
        addStartingNodes(q,routes,source);
        vector<int> vis(routes.size(),0);
        int busCount=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                if(isStopExist(routes[node],target)) return busCount;
                for(int ad:adj[node]){
                    if(!vis[ad]){
                        vis[ad]=1;
                        q.push(ad);
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};