class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        vector<vector<int>> res;
        int i=0,j=0;
        while(i<first.size() and j<second.size())
        {
            if((first[i][0]>=second[j][0] and first[i][0]<=second[j][1]) or    (second[j][0]>=first[i][0] and second[j][0]<=first[i][1]))
            {
                int start=max(first[i][0],second[j][0]);
                int end=min(first[i][1],second[j][1]);
                res.push_back({start,end});
            }
            if(first[i][1]<second[j][1]) i++;
            else j++;
        }
        return res;
    }
};