class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0) return image;
        int row=image.size();
        int col=image[0].size();
        int old=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr-1,sc});
        q.push({sr+1,sc});
        q.push({sr,sc-1});
        q.push({sr,sc+1});
        image[sr][sc]=newColor;
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vis[sr][col]=true;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x>=0 and x<row and y>=0 and y<col and !vis[x][y] and image[x][y]==old)
            {
                vis[x][y]=true;
                image[x][y]=newColor;
                q.push({x-1,y});
                q.push({x+1,y});
                q.push({x,y-1});
                q.push({x,y+1});
            }
        }
        return image;
    }
};