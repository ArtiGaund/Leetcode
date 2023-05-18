class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,false);
        for(auto e:edges)
            indegree[e[1]]=true;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(!indegree[i]) res.push_back(i);
        }
        return res;
    }
};