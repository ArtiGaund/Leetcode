class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> res(n,vector<int>(n));
        int top=0,bottom=n-1,left=0,right=n-1,k=1;
        while(k<=n*n)
        {
            for(int i=left;i<=right;i++)
            {
                res[top][i]=k;
                k++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                res[i][right]=k;
                k++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                res[bottom][i]=k;
                k++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                res[i][left]=k;
                k++;
            }
            left++;
        }
        return res;
    }
};