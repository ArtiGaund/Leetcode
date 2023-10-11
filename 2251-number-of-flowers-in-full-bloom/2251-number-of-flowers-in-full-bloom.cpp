class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        for(auto f:flowers)
        {
            starts.push_back(f[0]);
            ends.push_back(f[1]+1);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        vector<int> res;
        for(auto p:people)
        {
            int i=upper_bound(starts.begin(),starts.end(),p)-starts.begin();
            int j=upper_bound(ends.begin(),ends.end(),p)-ends.begin();
            res.push_back(i-j);
        }
        return res;
    }
};