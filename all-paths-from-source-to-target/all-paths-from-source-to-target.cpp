class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp={0};
        dfs(graph,temp,0);
        return res;
    }
    void dfs(vector<vector<int>> &v,vector<int> &temp,int start)
    {
        if(start==v.size()-1)
        {
            res.push_back(temp);
            return;
        }
        for(auto i:v[start])
        {
            temp.push_back(i);
            dfs(v,temp,i);
            temp.pop_back();
        }
    }
};