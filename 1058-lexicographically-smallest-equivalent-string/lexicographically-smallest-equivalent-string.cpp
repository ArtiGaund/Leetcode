class Solution {
public:
char dfs(unordered_map<char,vector<char>> &adj,char cur,vector<int> &vis){
    vis[cur-'a']=1;
    char minChar =cur;
    for(char nei:adj[cur]){
        if(vis[nei-'a']==0){
            minChar = min(minChar,dfs(adj,nei,vis));
        }
    }
    return minChar;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res;
        for(char ch:baseStr){
            vector<int> vis(26,0);
            char minChar = dfs(adj,ch,vis);
            res.push_back(minChar);
        }
        return res;
    }
};