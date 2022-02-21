class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        int n=rooms[0].size();
        if(m==0) return;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rooms[i][j]==0)
                    q.push({i,j});
            }
        }
        vector<vector<int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int row=cur.first;
            int col=cur.second;
            for(vector<int> d:dir)
            {
                int r=row+d[0];
                int c=col+d[1];
                if(r<0 or r>=m or c<0 or c>=n or rooms[r][c]!=2147483647) continue;
                rooms[r][c]=rooms[row][col]+1;
                q.push({r,c});
            }
        }
    }
};