class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOngoing;
        for(int i=0;i<paths.size();i++)
            hasOngoing.insert(paths[i][0]);
        for(int i=0;i<paths.size();i++){
            string cand=paths[i][1];
            if(hasOngoing.find(cand)==hasOngoing.end()) return cand;
        }
        return "";
    }
};