/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int n=schedule.size();
        // error checking
        if(n==0) return {};
        // breaking down into intervals
        vector<vector<int>> intervals;
        for(auto employee:schedule)
        {
            for(auto interval:employee)
                intervals.push_back({interval.start,interval.end});
        }
        //sorting the interval according to start time
        sort(intervals.begin(),intervals.end());
        // loop through intervals to find free time
        vector<Interval> res;
        int lastend=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int curStart=intervals[i][0];
            int curEnd=intervals[i][1];
            if(curStart>lastend)
                res.push_back(Interval(lastend,curStart));
            lastend=max(lastend,curEnd);
        }
        return res;
    }
};