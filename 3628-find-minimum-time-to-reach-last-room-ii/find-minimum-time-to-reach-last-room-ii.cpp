class State{
    public:
    int x,y,dis;
    State(int x,int y,int dis):x(x),y(y),dis(dis){}
};
class Solution {
public:
const int inf=0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int>> d(n,vector<int>(m,inf));
        vector<vector<int>> v(n,vector<int>(m,0));
        int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        d[0][0]=0;
        auto comp= [](const State &a,const State &b){
            return a.dis>b.dis;
        };
        priority_queue<State,vector<State>,decltype(comp)> q(comp);
        q.push(State(0,0,0));
        while(!q.empty()){
            State st=q.top();
            q.pop();
            if(v[st.x][st.y]) continue;
            if(st.x==n-1 and st.y==m-1) break;
            v[st.x][st.y]=1;
            for(int i=0;i<4;i++){
                int nx=st.x+dirs[i][0];
                int ny=st.y+dirs[i][1];
                if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
                int dist=max(d[st.x][st.y],moveTime[nx][ny])+(st.x+st.y)%2+1;
                if(d[nx][ny]>dist){
                    d[nx][ny]=dist;
                    q.push(State(nx,ny,dist));
                }
            }
        }
        return d[n-1][m-1];
    }
};