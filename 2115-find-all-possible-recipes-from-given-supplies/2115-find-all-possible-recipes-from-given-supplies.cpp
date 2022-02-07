class Solution {
public:
    //BFS
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        map<string,int> indegree;
        for(int i=0;i<ingredients.size();i++)
        {
            for(string s:ingredients[i])
            {
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string> q;
        for(string item:supplies)
            if(indegree[item]==0) q.push(item);
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            for(auto it:adj[cur])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        vector<string> res;
        for(string s:recipes)
            if(indegree[s]==0) res.push_back(s);
        return res;
    }
};