class Solution {
public:
    void solve(int si,int sj,vector<vector<int>> &mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> temp;
        int i=si,j=sj;
        int index=0;
        while(i<n&&j<m)
        {
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        index=0;
        i=si;
        j=sj;
        while(i<n&&j<m)
        {
            mat[i][j]=temp[index];
            i++;
            j++;
            index++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
            solve(i,0,mat);
        for(int j=1;j<m;j++)
            solve(0,j,mat);
        return mat;
    }
};