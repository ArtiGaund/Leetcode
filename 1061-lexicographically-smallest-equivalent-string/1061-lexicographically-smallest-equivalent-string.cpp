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
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void unionset(int a,int b)
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
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for(int i=0;i<s1.size();i++)
        {
            int first=s1[i]-'a';
            int sec=s2[i]-'a';
            uf.unionset(first,sec);
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                if(uf.find(j)==uf.find(baseStr[i]-'a'))
                {
                    ans+=(j+'a');
                    break;
                }
            }
        }
        return ans;
        
    }
};