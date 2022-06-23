class Solution {
public:
    int bfs(int sr,int sc,int er,int ec,vector<vector<int>> &mat){
        if(mat[sr][sc]==mat[er][ec]) return 0;
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        
        queue<pair<int,int>> qq; qq.push({sr,sc});
        int level=0;
        vis[sr][sc]=1;
        while(qq.size()){
            int sz=qq.size();
            level++;
            while(sz--){
                auto pos=qq.front(); qq.pop();
                for(auto d:dir){
                    int x=pos.first+d.first;
                    int y=pos.second+d.second;
                    if(x>=0 and y>=0 and x<n and y<m and !vis[x][y] and mat[x][y]!=0){
                        vis[x][y]=1;
                        qq.push({x,y});
                        if(x==er and y==ec) return level;
                    }
                }   
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest[0][0]==0) return -1;
        int m=forest.size();
        int n=forest[0].size();
        map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(forest[i][j]>1)
                    mp[forest[i][j]]={i,j};
            }
        }
        int ans=0,x=0,y=0;
        for(auto &v:mp)
        {
            int temp=bfs(x,y,v.second.first,v.second.second,forest);
            if(temp==-1) return -1;
            ans+=temp;
            x=v.second.first;
            y=v.second.second;
        }
        return ans;
    }
};