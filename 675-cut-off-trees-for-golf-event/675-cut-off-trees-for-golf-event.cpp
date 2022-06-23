class Solution {
public:
    int n,m;
    vector<vector<int>> mat;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int bfs(int sr,int sc,int er,int ec){
        if(mat[sr][sc]==mat[er][ec]) return 0;
        
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        
        queue<pair<int,int>> qq; qq.push({sr,sc});
        int level=0;
        vis[sr][sc]=1;
        while(qq.size()){
            int sz=qq.size();
            level++;
            while(sz--){
                auto pos=qq.front(); qq.pop();
                for(int i=0;i<4;i++){
                    int x=pos.first+dx[i];
                    int y=pos.second+dy[i];
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
        if(forest[0][0]==0) return -1;//always start from (0,0)
        
        mat=forest;
        n=forest.size(); m=forest[0].size();
        map<int,pair<int,int>> vals;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    vals[forest[i][j]]={i,j};
                }
            }
        }
        
        int ans=0;
        int x1=0,y1=0;
        for(auto &v: vals){
            int temp=bfs(x1,y1,v.second.first,v.second.second);
            if(temp==-1) return -1;
            ans+=temp;
            x1=v.second.first; y1=v.second.second;
        }
        
        return ans;
    }
};