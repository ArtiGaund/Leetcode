class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0) return false;
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int pivot=low+(high-low)/2;
            int row=pivot/m;
            int col=pivot%m;
            int ele=matrix[row][col];
            if(ele==target) return true;
            else if(ele<target) low=pivot+1;
            else high=pivot-1;
        }
        return false;
    }
};