class UnionFind
{
    private:vector<int> root;
            vector<int> rank;
    public:
    UnionFind(int size):root(size),rank(size)
    {
        for(int i=0;i<size;i++)
        {
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x)
    {
        if(x==root[x]) return x;
        return root[x]=find(root[x]);
    }
    void unionset(int x,int y)
    {
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty)
        {
            if(rank[rootx]>=rank[rooty])
            {
                root[rooty]=rootx;
                rank[rootx]+=rank[rooty];
            }
            else
            {
                root[rootx]=rooty;
                rank[rooty]+=root[rootx];
            }
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(vector<int> &e:pairs)
        {
            int s=e[0];
            int d=e[1];
            uf.unionset(s,d);
        }
        unordered_map<int,vector<int>> rootToComp;
        for(int vertex=0;vertex<s.size();vertex++)
        {
            int root=uf.find(vertex);
            rootToComp[root].push_back(vertex);
        }
        string res(s.size(),' ');
        for(auto comp:rootToComp)
        {
            vector<int> indices=comp.second;
            vector<char> characters;
            for(int index:indices)
                characters.push_back(s[index]);
            sort(characters.begin(),characters.end());
            for(int index=0;index<indices.size();index++)
                res[indices[index]]=characters[index];
        }
        return res;
    }
};