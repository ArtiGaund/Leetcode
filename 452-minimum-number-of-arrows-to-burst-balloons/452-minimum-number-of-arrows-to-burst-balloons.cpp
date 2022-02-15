class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        sort(points.begin(),points.end(),compare);
        vector<int> prev=points[0];
        int arrow=1;
        for(int i=1;i<n;i++)
        {
            vector<int> cur=points[i];
            if(cur[0]>prev[1])
            {
                arrow++;
                prev=cur;
            }
        }
        return arrow;
    }
};