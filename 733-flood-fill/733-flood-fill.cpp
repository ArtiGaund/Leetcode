class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       if(image.size()==0) return image;
        int row=image.size();
        int col=image[0].size();
        queue<pair<int,int>> q;
        int oldcolor=image[sr][sc];
        image[sr][sc]=newColor;
        q.push({sr-1,sc});
        q.push({sr+1,sc});
        q.push({sr,sc-1});
        q.push({sr,sc+1});
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vis[sr][sc]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                int l=p.first;
                int r=p.second;
                q.pop();
                if(l>=0 and l<row and r>=0 and r<col and !vis[l][r] and image[l][r]==oldcolor)
                {
                    vis[l][r]=true;
                    image[l][r]=newColor;
                    q.push({l-1,r});
                    q.push({l+1,r});
                    q.push({l,r-1});
                    q.push({l,r+1});
                }
            }
        }
        return image;
    }
};