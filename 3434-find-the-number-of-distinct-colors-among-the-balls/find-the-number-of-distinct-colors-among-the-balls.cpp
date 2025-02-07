class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> res(n);
        unordered_map<int,int> colorMp,ballMp;
        for(int i=0;i<n;i++){
            int ball=queries[i][0],color=queries[i][1];
            if(ballMp.find(ball)!=ballMp.end()){
                int prevColor=ballMp[ball];
                colorMp[prevColor]--;
                if(colorMp[prevColor]==0) colorMp.erase(prevColor);
            }
            ballMp[ball]=color;
            colorMp[color]++;
            res[i]=colorMp.size();
        }
        return res;
    }
};