class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<bool> vis(n,false);
        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                res++;
                s.push(i);
                while(!s.empty())
                {
                    int cur=s.top();
                    s.pop();
                    vis[cur]=true;
                    for(int j=0;j<v[cur].size();j++)
                        if(!vis[j] and v[cur][j]==1) s.push(j);
                }
            }
        }
        return res;
    }
};