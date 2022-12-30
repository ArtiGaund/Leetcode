class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp={0};
        backtrack(graph,temp,0);
        return res;
    }
    void backtrack(vector<vector<int>> &graph,vector<int> &temp,int i)
    {
        if(i==graph.size()-1)
        {
            res.push_back(temp);
            return;
        }
        for(auto it:graph[i])
        {
            temp.push_back(it);
            backtrack(graph,temp,it);
            temp.pop_back();
        }
    }
};