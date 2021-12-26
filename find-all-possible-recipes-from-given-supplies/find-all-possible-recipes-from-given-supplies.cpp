class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>> adj; //map to store the graph
        unordered_map<string,int> indegree; //count indegree of every vertex
        for(int i=0;i<ing.size();i++)
        {
            for(int j=0;j<ing[i].size();j++)
            { 
                adj[ing[i][j]].push_back(rec[i]); //to get recipes[i] we first have to complete/made its ingredients
                indegree[rec[i]]++;
            }
        }
        vector<string> ans;
        //apply kahn's alg
        queue<string> q;
        for(int i=0;i<sup.size();i++) q.push(sup[i]);
        while(!q.empty())
        {
            string front=q.front();
            q.pop();
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};