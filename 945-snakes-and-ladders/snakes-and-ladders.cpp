// this version puts larger index prior which can skip steps
int flatten[400];
uint16_t dist[400];
int n;
class Solution {
public:
    static void build_flatten(vector<vector<int>>& board) {     
        for (int i=n-1; i>=0; i-=2) {
            for (int j=0; j<n; j++) {
                flatten[(n-1-i)*n+j] = board[i][j]-1; // index-1 -> index-0
                if (i-1 >= 0)
                    flatten[(n-i)*n+(n-1-j)] = board[i-1][j]-1;
            }
        }
    }
        
    static int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        build_flatten(board); 
        fill(dist, dist+n*n, USHRT_MAX);// fill with USHRT_MAX
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(511);// 511-curr let larger index prior
        dist[0]=0;
        while (!pq.empty()) {
            int data=pq.top(); 
            int d=data>>9, curr=511-(data&511);
        //    cout<<curr<<":"<<d<<endl;
            pq.pop();
            if (dist[curr]<d) continue;
            if (curr==n*n-1)
                return d;
            int i0=min(6, n*n-1-curr); 
            for (int i=1; i<=i0; i++) {
                int next=curr+i;           
                if (flatten[next]!=-2) next=flatten[next];
                if (dist[next]>d+1){
                    dist[next]=d+1;
                    pq.push((dist[next]<<9)+511-next);
                }
            }
        }  
        return -1;  
    }
};