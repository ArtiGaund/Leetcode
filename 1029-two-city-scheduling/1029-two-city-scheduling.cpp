class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total=0;
        vector<int> diff;
        for(auto it:costs)
        {
            total+=it[0];
            diff.push_back(it[1]-it[0]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<diff.size()/2;i++)
            total+=diff[i];
        return total;
    }
};