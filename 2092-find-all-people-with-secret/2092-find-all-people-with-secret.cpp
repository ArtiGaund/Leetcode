class UnionFind
{
    public:
    vector<int> parent,rank;
    UnionFind(int n):parent(n),rank(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
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
        }
    }
    bool connected(int a,int b)
    {
        return find(a)==find(b);
    }
    void reset(int a)
    {
        parent[a]=a;
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),comp);
        UnionFind uf(n);
        uf.unionset(0,firstPerson);
        for(int i=0;i<meetings.size();)
        {
            unordered_set<int> s;
            int time=meetings[i][2];
            while(i<meetings.size() and time==meetings[i][2])
            {
                s.insert(meetings[i][0]);
                s.insert(meetings[i][1]);
                uf.unionset(meetings[i][0],meetings[i][1]);
                i++;
            }
            for(int person:s)
            {
                if(uf.connected(0,person)==false)
                    uf.reset(person);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(uf.connected(0,i)) res.push_back(i);
        return res;
    }
};