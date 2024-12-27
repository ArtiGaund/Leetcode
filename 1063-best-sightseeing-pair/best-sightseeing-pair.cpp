class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxLeftScore=values[0];
        int maxScore=0;
        for(int i=1;i<n;i++){
            int curRightScore=values[i]-i;
            maxScore=max(maxScore,maxLeftScore+curRightScore);
            int curLeftScore=values[i]+i;
            maxLeftScore=max(maxLeftScore,curLeftScore);
        }
        return maxScore;
    }
};