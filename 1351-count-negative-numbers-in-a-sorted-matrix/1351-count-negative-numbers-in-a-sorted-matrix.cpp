class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid[0].size();
        int curRowNegIndex=n-1;
        for(auto r:grid)
        {
            while(curRowNegIndex>=0 and r[curRowNegIndex]<0) curRowNegIndex--;
            count+=(n-(curRowNegIndex+1));
        }
        return count;
    }
};