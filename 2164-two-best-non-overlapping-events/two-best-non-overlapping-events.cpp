class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int,3>> times;
        for(auto e:events){
            times.push_back({e[0],1,e[2]}); //start time
            times.push_back({e[1]+1,0,e[2]}); //end time
        }
        int res=0,maxVal=0;
        sort(times.begin(),times.end());
        for(auto timeVal:times){
            if(timeVal[1]) res=max(res,timeVal[2]+maxVal);
            else maxVal=max(maxVal,timeVal[2]);
        }
        return res;
    }
};