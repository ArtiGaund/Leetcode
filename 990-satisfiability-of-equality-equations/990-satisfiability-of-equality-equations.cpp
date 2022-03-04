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
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        UnionFind uf(26);
        for(auto e:equations)
        {
            if(e[1]=='=')
                uf.unionset(e[0]-'a',e[3]-'a');
        }
        for(auto e:equations)
        {
            if(e[1]=='!')
                if(uf.find(e[0]-'a')==uf.find(e[3]-'a')) return false;
        }
        return true;
    }
};