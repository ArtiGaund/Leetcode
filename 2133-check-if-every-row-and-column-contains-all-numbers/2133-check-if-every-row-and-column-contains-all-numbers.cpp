class Solution {
public:
    bool check(vector<bool> &f)
    {
        for(int i=1;i<f.size();i++)
            if(!f[i]) return false;
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            vector<bool> found(n+1,false);
            for(int j=0;j<n;j++)
                found[matrix[i][j]]=true;
            if(!check(found)) return false;
        }
        for(int i=0;i<n;i++)
        {
             vector<bool> found(n+1,false);
            for(int j=0;j<n;j++)
                found[matrix[j][i]]=true;
            if(!check(found)) return false;
        }
        return true;
    }
};