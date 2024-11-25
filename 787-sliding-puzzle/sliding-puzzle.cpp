class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        string target="123450";
        string startState;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                startState+=to_string(board[i][j]);
            }
        }
        unordered_set<string> vis;
        queue<string> q;
        q.push(startState);
        vis.insert(startState);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            while(size-- >0){
                string curState=q.front();
                q.pop();
                if(curState==target){
                    return moves;
                }
                int zeroPos=curState.find('0');
                for(int newPos:dir[zeroPos]){
                    string nextState=curState;
                    swap(nextState[zeroPos],nextState[newPos]);
                    if(vis.count(nextState)) continue;
                    vis.insert(nextState);
                    q.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};