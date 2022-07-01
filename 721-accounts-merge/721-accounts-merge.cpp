class UnionFind
{
    public:vector<int> parent,rank;
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
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        UnionFind uf(n);
        unordered_map<string,int> emailGroup;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string email=accounts[i][j];
                if(emailGroup.count(email)==0)
                    emailGroup[email]=i;
                else uf.unionset(i,emailGroup[email]);
            }
        }
        unordered_map<int,vector<string>> components;
        for(auto it:emailGroup)
        {
            string email=it.first;
            int group=it.second;
            components[uf.find(group)].push_back(email);
        }
        vector<vector<string>> res;
        for(auto it:components)
        {
            int group=it.first;
            vector<string> email={accounts[group][0]};
            for(auto &s:it.second) email.push_back(s);
            sort(email.begin()+1,email.end());
            res.push_back(email);
        }
        return res;
    }
};