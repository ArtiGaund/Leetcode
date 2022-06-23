class Solution {
public:
    bool dfs(unordered_map<string,vector<string>> &adj,vector<string> &res,string s,int size)
    {
        if(res.size()==size+1) return true;
        if(adj[s].size()==0) return false;
        for(int i=0;i<adj[s].size();i++)
        {
            if(adj[s][i]!="-1")
            {
                string temp=adj[s][i];
                res.push_back(temp);
                adj[s][i]="-1";
                if(dfs(adj,res,temp,size)) return true;
                adj[s][i]=temp;
                res.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto &t:tickets) adj[t[0]].push_back(t[1]);
        for(auto x:adj)
            sort(adj[x.first].begin(),adj[x.first].end());
        vector<string> res;
        string s="JFK";
        res.push_back(s);
        int size=tickets.size();
        dfs(adj,res,s,size);
        return res;
    }
};