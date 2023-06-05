class Solution {
public:
    int getYDiff(vector<int> &a,vector<int> &b)
    {
        return a[1]-b[1];
    }
    int getXDiff(vector<int> &a,vector<int> &b)
    {
        return a[0]-b[0];
    }
    bool checkStraightLine(vector<vector<int>>& coord) {
        int dY=getYDiff(coord[1],coord[0]);
        int dX=getXDiff(coord[1],coord[0]);
        for(int i=2;i<coord.size();i++)
        {
            if(dY*getXDiff(coord[i],coord[0])!=dX*getYDiff(coord[i],coord[0]))
                return false;
    
        }
        return true;
    }
};