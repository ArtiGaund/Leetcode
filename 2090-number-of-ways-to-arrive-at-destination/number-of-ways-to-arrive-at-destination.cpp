class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>> graph(n);
        for(auto road:roads){
            int start=road[0],end=road[1],time=road[2];
            graph[start].push_back({end,time});
            graph[end].push_back({start,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> minHeap;
        vector<long long> shortestTime(n,LLONG_MAX);
        vector<int> pathCount(n,0);
        shortestTime[0]=0;
        pathCount[0]=1;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            long long curTime=minHeap.top().first;
            int curNode=minHeap.top().second;
            minHeap.pop();
            if(curTime>shortestTime[curNode]) continue;
            for(auto &[nei,roadTime]:graph[curNode]){
                if(curTime+roadTime<shortestTime[nei]){
                    shortestTime[nei]=curTime+roadTime;
                    pathCount[nei]=pathCount[curNode];
                    minHeap.push({shortestTime[nei],nei});
                }else if(curTime+roadTime==shortestTime[nei]){
                    pathCount[nei]=(pathCount[nei]+pathCount[curNode])%MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};