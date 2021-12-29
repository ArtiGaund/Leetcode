class Solution {
public:
    int n,m;
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> v;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                    v.push_back({i,j});
            }
        }
        for(int i=0;i<v.size();i++)
            if(dfs(v[i][0],v[i][1],vis,board,word,1)) return true;
        return false;
    }
    bool dfs(int x,int y,vector<vector<bool>> &vis,vector<vector<char>> &matrix,string word,int index)
    {
        if(index==word.size()) return true;
        vis[x][y]=true;
        if(isSafe(x+1,y,vis))
        {
            if(word[index]==matrix[x+1][y])
                if(dfs(x+1,y,vis,matrix,word,index+1)) return true;
        }
        if(isSafe(x-1,y,vis))
        {
            if(word[index]==matrix[x-1][y])
                 if(dfs(x-1,y,vis,matrix,word,index+1)) return true;
        }
        if(isSafe(x,y+1,vis))
        {
            if(word[index]==matrix[x][y+1])
                 if(dfs(x,y+1,vis,matrix,word,index+1)) return true;
        }
        if(isSafe(x,y-1,vis))
        {
            if(word[index]==matrix[x][y-1])
                 if(dfs(x,y-1,vis,matrix,word,index+1)) return true;
        }
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