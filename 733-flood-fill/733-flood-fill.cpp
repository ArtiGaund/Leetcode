class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       if(image.size()==0) return image;
        int row=image.size();
        int col=image[0].size();
        int old=image[sr][sc];
        image[sr][sc]=newColor;
        queue<pair<int,int>> q; //to store the boundaries of visited vertix
        q.push({sr-1,sc});
         q.push({sr+1,sc});
         q.push({sr,sc-1});
         q.push({sr,sc+1});
        vector<vector<bool>> vis(row,vector<bool>(col,false)); //for checking visited cell
        vis[sr][sc]=true;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int l=p.first;
            int r=p.second;
            if(l>=0 and l<row and r>=0 and r<col and !vis[l][r] and image[l][r]==old) // check for 
            {
                image[l][r]=newColor;
                vis[l][r]=true;
                 q.push({l-1,r});
                 q.push({l+1,r});
                 q.push({l,r-1});
                 q.push({l,r+1});
            }
        }
        return image;
    }
};