class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> rowCount(m,0);
        vector<int> colCount(n,0);
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(mat[r][c]==1){
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        int res=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(mat[r][c]==1){
                    if(rowCount[r]==1 and colCount[c]==1) res++;
                }
            }
        }
        return res;
    }
};