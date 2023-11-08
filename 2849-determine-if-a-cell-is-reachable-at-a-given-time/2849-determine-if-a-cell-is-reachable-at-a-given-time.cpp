class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width=abs(sx-fx);
        int height= abs(sy-fy);
        if(width==0 and height==0 and t==1) return false;
        return t>=max(width,height);
    }
};