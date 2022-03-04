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
            else if(rank[y]>rank[x]) parent[x]=y;
            else
            {
                parent[y]=x;
                rank[x]++;
            }
            return true;
        }
        return false;
    }
    int getCount()
    {
        return count;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        int n=equations.size();
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
                uf.unionset(equations[i][0]-'a',equations[i][3]-'a');
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
                if(uf.find(equations[i][0]-'a')==uf.find(equations[i][3]-'a')) return false;
        }
        return true;
    }
};