class Solution {
public:
    void dfs(string &s,string &d,unordered_map<string,vector<pair<string,double>>> &graph,unordered_set<string> &vis,double &ans,double temp)
    {
        if(vis.count(s)>0) return;
        vis.insert(s);
        if(s==d)
        {
            ans=temp;
            return;
        }
        for(auto a:graph[s])
            dfs(a.first,d,graph,vis,ans,temp*a.second);
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<eq.size();i++)
        {
            graph[eq[i][0]].push_back({eq[i][1],val[i]});
            graph[eq[i][1]].push_back({eq[i][0],1/val[i]});
        }
        vector<double> res;
        for(auto q:queries)
        {
            string s=q[0];
            string d=q[1];
            unordered_set<string> vis;
            double ans=-1.0;
            if(graph.find(s)!=graph.end()) dfs(s,d,graph,vis,ans,1.0);
            res.push_back(ans);
        }
        return res;
    }
};