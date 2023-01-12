class UnionFind
{
    public:
        unordered_map<int,int> parent;
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        if(parent.count(u)==0) parent[u]=u;
        if(parent.count(v)==0) parent[v]=v;
        int pu=findParent(u),pv=findParent(v);
        if(pu!=pv) parent[pu]=pv;
    }
    unordered_map<int,vector<int>> getgroup()
    {
        unordered_map<int,vector<int>> groups;
        for(auto &[u,v]:parent) groups[findParent(u)].push_back(u);
        return groups;
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        map<int,vector<pair<int,int>>> groupByValue;
        for(int r=0;r<m;r++)
            for(int c=0;c<n;c++)
                groupByValue[matrix[r][c]].push_back({r,c});
        vector<int> rank(m+n,0);
        for(auto &[val,cells]:groupByValue)
        {
            UnionFind uf;
            for(auto &[r,c]:cells)
                uf.unionset(r,c+m);
            for(auto &[val,group]:uf.getgroup())
            {
                int maxRank=0;
                for(int i:group) maxRank=max(maxRank,rank[i]);
                for(int i:group) rank[i]=maxRank+1;
            }
            for(auto &[r,c]:cells) matrix[r][c]=rank[r];
        }
        return matrix;
    }
};