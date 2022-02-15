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
    typedef pair<int,int> pii;
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int n=schedule.size();
        // error checking
        if(n==0) return {};
        // breaking down into intervals
        // vector<vector<int>> intervals; 
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto employee:schedule)
        {
            for(auto interval:employee)
                pq.push({interval.start,interval.end});
        }
        //sorting the interval according to start time
        // sort(intervals.begin(),intervals.end());
        // loop through intervals to find free time
        vector<Interval> res;
        int lastend=pq.top().second;
        pq.pop();
        while(!pq.empty())
        {
            int curStart=pq.top().first;
            int curEnd=pq.top().second;
            pq.pop();
            if(curStart>lastend)
                res.push_back(Interval(lastend,curStart));
            lastend=max(lastend,curEnd);
        }
        return res;
    }
};