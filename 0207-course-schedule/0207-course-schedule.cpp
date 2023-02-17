class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> topo;
        if(num<=0) return false;
        unordered_map<int,int> indegree;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<num;i++)
        {
            indegree[i]=0;
            graph[i]=vector<int>();
        }
        for(int i=0;i<pre.size();i++)
        {
            int parent=pre[i][0],child=pre[i][1];
            graph[parent].push_back(child);
            indegree[child]++;
        }
        queue<int> source;
        for(auto it:indegree)
        {
            if(it.second==0)
                source.push(it.first);
        }
        while(!source.empty())
        {
            int vertex=source.front();
            source.pop();
            topo.push_back(vertex);
            for(auto child:graph[vertex])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    source.push(child);
            }
        }
        if(topo.size()!=num) return false;
        return true;
    }
};