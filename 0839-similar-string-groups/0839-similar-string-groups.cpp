class UnionFind
{
    public:
    vector<int> parent,rank;
    int count;
    UnionFind(int n):parent(n),rank(n),count(n)
    {
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int x)
    {
        if(parent[x]!=x)
            return parent[x]=findParent(parent[x]);
        return parent[x];
    }
    void unionset(int a,int b)
    {
        int x=findParent(a);
        int y=findParent(b);
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[x]>rank[y]) parent[y]=x;
        else
        {
            parent[x]=y;
            rank[y]++;
        }
    }
};
class Solution {
public:
    bool isSimilar(string a,string b)
    {
        int diff=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i]) diff++;
        }
        return (diff==0 or diff==2);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        UnionFind uf(n);
        int count=n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isSimilar(strs[i],strs[j]) and uf.findParent(i)!=uf.findParent(j))
                {
                    count--;
                    uf.unionset(i,j);
                }
            }
        }
        return count;
    }
};