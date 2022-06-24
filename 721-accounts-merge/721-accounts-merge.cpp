class Solution {
public:
    unordered_map<string,vector<int>> mp;
    vector<bool> vis;
    void dfs(vector<vector<string>> &accounts,int i,set<string> &emails)
    {
        if(vis[i]) return;
        vis[i]=true;
        for(int j=1;j<accounts[i].size();j++)
        {
            string cur=accounts[i][j];
            emails.insert(cur);
            for(auto it:mp[cur]) dfs(accounts,it,emails);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=0;j<accounts[i].size();j++)
                mp[accounts[i][j]].push_back(i);
        }
        vis.assign(accounts.size(),0);
        vector<vector<string>> res;
        for(int i=0;i<accounts.size();i++)
        {
            if(vis[i]) continue;
            set<string> emails;
            dfs(accounts,i,emails);
            vector<string> temp={accounts[i][0]};
            for(auto str:emails) temp.push_back(str);
            res.push_back(temp);
        }
        return res;
    }
};