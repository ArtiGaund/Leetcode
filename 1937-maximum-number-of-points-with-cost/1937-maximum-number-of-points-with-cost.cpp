class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows=points.size();
        int cols=points[0].size();
        vector<long long> prev(cols);
        for(int j=0;j<cols;j++) prev[j]=points[0][j];
        for(int i=0;i<rows-1;i++)
        {
            vector<long long> left(cols),right(cols),cur(cols);
            left[0]=prev[0];
            right[cols-1]=prev[cols-1];
            for(int j=1;j<cols;j++)
                left[j]=max(left[j-1]-1,prev[j]);
            for(int j=cols-2;j>=0;j--)
                right[j]=max(right[j+1]-1,prev[j]);
            for(int j=0;j<cols;j++)
                cur[j]=points[i+1][j]+max(left[j],right[j]);
            prev=cur;
        }
        long long maxPoints=0;
        for(int i=0;i<cols;i++) maxPoints=max(maxPoints,prev[i]);
        return maxPoints;
    }
};