class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i=1;i<travel.size();i++)
            travel[i]=travel[i-1]+travel[i];
        unordered_map<char,int> garbageLastPos;
        int res=0;
        for(int i=0;i<garbage.size();i++){
            for(char ch:garbage[i]){
                garbageLastPos[ch]=i;
            }
            res+=garbage[i].size();
        }
        string garbageTypes="MPG";
        for(char ch:garbageTypes){
            res+=(garbageLastPos[ch]==0?0: travel[garbageLastPos[ch]-1]);
        }
        return res;
    }
};