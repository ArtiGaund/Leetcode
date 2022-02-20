class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,left=-1,right=-1;
        for(auto cur:intervals)
        {
            if(cur[0]>left and cur[1]>right)
            {
                count++;
                left=cur[0];
            }
            right=max(right,cur[1]);
        }
        return count;
    }
};