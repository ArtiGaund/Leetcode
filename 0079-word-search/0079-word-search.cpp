class Solution {
public:
    int n,m;
    bool exist(vector<vector<char>>& b, string w) {
        n=b.size();
        m=b[0].size();
        vector<vector<int>> v;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(b[i][j]==w[0]) v.push_back({i,j});
        for(int i=0;i<v.size();i++)
            if(dfs(v[i][0],v[i][1],b,w,vis,1)) return true;
        return false;
    }
    bool dfs(int x,int y,vector<vector<char>> &b,string w,vector<vector<bool>> &vis,int index)
    {
        if(index==w.size()) return true;
        vis[x][y]=true;
        if(isSafe(x+1,y,vis))
            if(b[x+1][y]==w[index])
                if(dfs(x+1,y,b,w,vis,index+1)) return true;
        if(isSafe(x-1,y,vis))
            if(b[x-1][y]==w[index])
                if(dfs(x-1,y,b,w,vis,index+1)) return true;
        if(isSafe(x,y+1,vis))
            if(b[x][y+1]==w[index])
                if(dfs(x,y+1,b,w,vis,index+1)) return true;
        if(isSafe(x,y-1,vis))
            if(b[x][y-1]==w[index])
                if(dfs(x,y-1,b,w,vis,index+1)) return true;
        vis[x][y]=false;
        return false;
    }
    bool isSafe(int x,int y,vector<vector<bool>> &vis)
    {
        if(x>=0 and x<n and y>=0 and y<m)
        {
            if(vis[x][y]==false) return true;
        }
        return false;
    }
};