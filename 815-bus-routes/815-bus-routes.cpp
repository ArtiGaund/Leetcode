class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, unordered_set<int>> graph;
        
        // For each of the stops, add the buses that travel from there
        for(int bus = 0; bus < routes.size(); bus++) {
            // iterate through the stops, and for each
            // bus stop add the corresponding bus that travels there
            for(int stop = 0; stop < routes[bus].size(); stop++) {
                graph[routes[bus][stop]].emplace(bus);
            }
        }
        if(graph.find(source)==graph.end() or graph.find(target)==graph.end()) return -1;
        unordered_set<int> vis;
        queue<int> q;
        q.push(source);
        int transition=0;
        while(!q.empty())
        {
            int size=q.size();
            transition++;
            for(int i=0;i<size;i++)
            {
                int curstop=q.front();
                q.pop();
                unordered_set<int> buses=graph[curstop];
                for(int bus:buses)
                {
                    if(vis.count(bus)) continue;
                    vis.insert(bus);
                    for(int stop:routes[bus])
                    {
                        if(stop==target) return transition;
                        else q.push(stop);
                    }
                }
            }
        }
        return -1;
    }
};