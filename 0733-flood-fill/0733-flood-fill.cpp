class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        if(image[sr][sc]==color) return image;
        int old=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr-1,sc});
        q.push({sr+1,sc});
        q.push({sr,sc-1});
        q.push({sr,sc+1});
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[sr][sc]=1;
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int r=cur.first,c=cur.second;
            if(r>=0 and r<m and c>=0 and c<n and image[r][c]==old and !vis[r][c])
            {
                vis[r][c]=1;
                image[r][c]=color;
                q.push({r-1,c});
                q.push({r+1,c});
                q.push({r,c-1});
                q.push({r,c+1});
            }
        }
        return image;
    }
};