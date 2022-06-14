class Solution {
public:
    int getIslandSize(vector<vector<int>> &grid,int i,int j,int islandId)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1) return 0;
        grid[i][j]=islandId;
        int left=getIslandSize(grid,i,j-1,islandId);
        int right=getIslandSize(grid,i,j+1,islandId);
        int up=getIslandSize(grid,i-1,j,islandId);
        int down=getIslandSize(grid,i+1,j,islandId);
        return left+right+up+down+1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 or n==0) return 0;
        int maxlen=0,islandId=2;
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int len=getIslandSize(grid,i,j,islandId);
                    maxlen=max(len,maxlen);
                    mp[islandId++]=len;
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> st;
                    for(auto d:dir)
                    {
                        int x=i+d.first,y=j+d.second;
                        if(x>=0 and x<m and y>=0 and y<n and grid[x][y]!=0)
                            st.insert(grid[x][y]);
                    }
                    int sum=1;
                    for(int num:st) sum+=mp[num];
                    maxlen=max(maxlen,sum);
                }
            }
        }
        return maxlen;
    }
};