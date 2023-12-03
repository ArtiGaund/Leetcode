class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
     int res=0;
        for(int i=0;i<points.size()-1;i++){
            int x=points[i][0],y=points[i][1];
            int targetX=points[i+1][0],targetY=points[i+1][1];
            res+=max(abs(targetX-x),abs(targetY-y));
        }
        return res;
    }
};