//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet
{
    public:
    vector<int> rank,parent;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())
                    mapMailNode[mail]=i;
                else
                {
                    ds.unionset(i,mapMailNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it:mapMailNode)
        {
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>> res;
        for(int i=0;i<n;i++)
        {
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i])
                temp.push_back(it);
            res.push_back(temp);
        }
        sort(res.begin(),res.end(),greater<vector<string>>());
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends