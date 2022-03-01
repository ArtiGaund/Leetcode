class UnionFind
{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(int n):parent(n),rank(n),count(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unionset(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            if(rank[x]>rank[y]) parent[y]=x;
            else if(rank[x]<rank[y]) parent[x]=y;
            else
            {
                parent[y]=x;
                rank[x]++;
            }
            count--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        //count incoming edges
        int nodewithtwoincoming=-1;
        for(auto e:edges)
        {
            mp[e[1]]++;
            if(mp[e[1]]==2) 
                nodewithtwoincoming=e[1];
        }
        if(nodewithtwoincoming==-1) // no node has 2 incoming edges then just find cycle
            return findRedundantConnection(edges,-1);
        // node which has 2 incoming edges skip them and try to build the graph
        //if graph can be build without cycle then skip node is the ans
        for(int i=edges.size()-1;i>=0;i--)
        {
            if(edges[i][1]==nodewithtwoincoming)
            {
                vector<int> res=findRedundantConnection(edges,i);
                if(res.empty()) return edges[i];
            }
        }
        return {};
    }
    vector<int> findRedundantConnection(vector<vector<int>> &e,int skip)
    {
        UnionFind uf(e.size()+1);
        for(int i=0;i<e.size();i++)
        {
            if(i==skip) continue;
            if(!uf.unionset(e[i][0],e[i][1])) return e[i];
        }
        return {};
    }
};