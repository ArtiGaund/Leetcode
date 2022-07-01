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
        unordered_map<string,int> emailGroup; // email->index
        for(int i=0;i<n;i++)
        {
            int size=accounts[i].size();
            for(int j=1;j<size;j++)
            {
                string email=accounts[i][j];
                string accName=accounts[i][0];
                if(emailGroup.count(email)==0) //not present
                    emailGroup[email]=i;
                else 
                    uf.unionset(i,emailGroup[email]); 
            }
        }
        unordered_map<int,vector<string>> components; //store email corresponding to comp
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
            vector<string> component={accounts[group][0]};
            for(string s:it.second) component.push_back(s);
            sort(component.begin()+1,component.end());
            res.push_back(component);
        }
        return res;
    }
};