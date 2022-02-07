class Solution {
public:
    //BFS
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=ingredients.size();
        unordered_map<string,vector<string>> adj;
        map<string,int> in;
        for(int i=0;i<n;i++)
        {
            for(string s:ingredients[i])
            {
                adj[s].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }
        queue<string> q;
        for(string items:supplies)
            if(in[items]==0) q.push(items);
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            for(string recipe:adj[cur])
            {
                in[recipe]--;
                if(in[recipe]==0) q.push(recipe);
            }
        }
        vector<string> res;
        for(string recipe:recipes)
            if(in[recipe]==0)
            res.push_back(recipe);
        return res;
    }
};