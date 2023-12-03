class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        for(int i=1;i<mountain.size()-1;i++){
            if(mountain[i-1]<mountain[i] and mountain[i+1]<mountain[i])
                res.push_back(i);
        }
        return res;
    }
};