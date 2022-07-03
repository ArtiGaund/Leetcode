class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
        for(int i=0;i<ingredients.size();i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string> q;
        for(string &s:supplies) q.push(s);
        vector<string> res;
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto it:adj[cur])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                    res.push_back(it);
                }
            }
        }
        return res;
    }
};