class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        if(n==0)
        {
            res.push_back(newInterval);
            return res;
        }
        int i=0;
        while(i<n and intervals[i][1]<newInterval[0])
            res.push_back(intervals[i++]);
        while(i<n and intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while(i<n)
            res.push_back(intervals[i++]);
        return res;
    }
};