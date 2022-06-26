class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res=0;
        for(int i=0;i<k;i++) res+=cardPoints[i];
        int cur=res;
        for(int i=k-1;i>=0;i--)
        {
            cur-=cardPoints[i];
            cur+=cardPoints[cardPoints.size()-k+i];
            res=max(res,cur);
        }
        return res;
    }
};