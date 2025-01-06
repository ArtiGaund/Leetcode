class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> res(n,0);
        int ballsToLeft=0,movesToLeft=0;
        int ballsToRight=0,movesToRight=0;
        for(int i=0;i<n;i++){
            // left pass
            res[i]+=movesToLeft;
            ballsToLeft+=boxes[i]-'0';
            movesToLeft+=ballsToLeft;

            // right pass
            int j=n-1-i;
            res[j]+=movesToRight;
            ballsToRight+=boxes[j]-'0';
            movesToRight+=ballsToRight;
        }
        return res;
    }
};