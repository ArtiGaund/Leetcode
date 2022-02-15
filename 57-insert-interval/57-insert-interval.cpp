class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merge;
        if(intervals.size()==0) 
        {
            merge.push_back(newInterval);
            return merge;
        }
        int i=0;
        int n=intervals.size();
        while(i<n and intervals[i][1]<newInterval[0]) //skip all intervals which comes before the new       
           merge.push_back(intervals[i++]);                // interval
        while(i<n and intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        merge.push_back(newInterval);
        while(i<n)
            merge.push_back(intervals[i++]);
        return merge;
    }
};