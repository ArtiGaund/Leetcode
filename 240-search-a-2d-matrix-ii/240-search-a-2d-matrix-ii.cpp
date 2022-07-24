class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int i=m;
        int j=0;
        while(i>=0&&j<=n)
        {
            if(target<matrix[i][j])
                i--;
            else if(target>matrix[i][j])
                j++;
            else
                return true;
        }
        return false;
    }
};