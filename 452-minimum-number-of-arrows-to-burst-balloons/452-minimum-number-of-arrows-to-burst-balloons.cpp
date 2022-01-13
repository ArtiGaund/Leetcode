class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n=points.size();
        if(n==0)
            return 0;
        int arrowPos=points[0][1];
        int arrowCount=1;
        for(int i=1;i<n;i++)
        {
            if(arrowPos>=points[i][0])
                continue;
            arrowCount++;
            arrowPos=points[i][1];
        }
        return arrowCount;
    }
};