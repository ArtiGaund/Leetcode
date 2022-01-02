class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res[60]={0};
        int c=0;
        for(int t:time)
        {
            if(t%60==0) c+=res[0];
            else c+=res[60-t%60];
            res[t%60]++;
        }
        return c;
    }
};