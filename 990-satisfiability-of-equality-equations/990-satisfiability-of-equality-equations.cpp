class UnionFind
{
    public:
    vector<int> parent,rank;
    UnionFind(int n):parent(n),rank(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int x)
    {
        if(x!=parent[x])
            x=find(parent[x]);
        return x;
    }
    void unionset(int a,int b)
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
            // return true;
        }
        // return false;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(string &s:equations)
        {
            if(s[1]=='=')
                uf.unionset(s[0]-'a',s[3]-'a');
        }
        for(string &s:equations)
        {
            if(s[1]=='!')
                if(uf.find(s[0]-'a')==uf.find(s[3]-'a')) return false;
        }
        return true;
    }
};