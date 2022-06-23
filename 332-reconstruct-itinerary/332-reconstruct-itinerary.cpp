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
        for(auto t:tickets) adj[t[0]].push_back(t[1]);
        for(auto it:adj)
            sort(adj[it.first].begin(),adj[it.first].end());
        vector<string> res;
        string str="JFK";
        res.push_back(str);
        int size=tickets.size();
        dfs(adj,res,str,size);
        return res;
    }
};