class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n<2) return 1;
        int componentCount=0;
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto e:edges){
            int node1=e[0],node2=e[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            indegree[node1]++;
            indegree[node2]++;
        }
        vector<long long> longVal(values.begin(),values.end());
        queue<int> q;
        for(int node=0;node<n;node++){
            if(indegree[node]==1) q.push(node);
        }
        while(!q.empty()){
            int curNode=q.front();
            q.pop();
            indegree[curNode]--;
            long long addVal=0;
            if(longVal[curNode]%k==0) componentCount++;
            else addVal=longVal[curNode];
            for(auto nei:graph[curNode]){
                if(indegree[nei]==0) continue;
                indegree[nei]--;
                longVal[nei]+=addVal;
                if(indegree[nei]==1) q.push(nei);
            }
        }
        return componentCount;
    }
};