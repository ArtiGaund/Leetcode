class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> res;
        for(int step=1,direction=0;res.size()<rows*cols;){
            for(int i=0;i<2;i++){
                for(int j=0;j<step;j++){
                    if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                        res.push_back({rStart,cStart});
                    }
                    rStart+=dir[direction][0];
                    cStart+=dir[direction][1];
                }
                direction=(direction+1)%4;
            }
            step++;
        }
        return res;
    }
};