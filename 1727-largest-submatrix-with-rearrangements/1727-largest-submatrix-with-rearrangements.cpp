class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height(n,0);
        int max_area=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(matrix[i][j]==1) height[j]+=1;
                else height[j]=0;
            vector<int> temp=height;
            sort(temp.begin(),temp.end());
            for(int j=0;j<n;j++)
                max_area=max(max_area,temp[j]*(n-j));
        }
        return max_area;
    }
};