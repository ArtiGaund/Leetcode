class Solution {
public:
    // like no of island problem
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        if(n==0) return 0;
        int count=0;
        set<int> vis;
        for(int i=0;i<n;i++)
        {
            if(vis.find(i)==vis.end())
            {
                count++;
                dfs(stones,vis,i);
            }
        }
        return n-count;
    }
    void dfs(vector<vector<int>> &stones,set<int> &vis,int index)
    {
        vis.insert(index);
        for(int i=0;i<stones.size();i++)
        {
            if(vis.find(i)!=vis.end()) continue;
            if(stones[i][0]==stones[index][0] or stones[i][1]==stones[index][1])
                dfs(stones,vis,i);
        }
    }
};