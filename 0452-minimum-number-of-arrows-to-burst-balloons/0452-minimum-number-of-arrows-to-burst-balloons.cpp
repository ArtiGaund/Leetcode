class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        sort(points.begin(),points.end());
        int count=0,end=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=end)
            {
                count++;
                end=min(end,points[i][1]);
            }
            else end=points[i][1];
        }
        return n-count;
    }
};