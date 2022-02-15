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
    typedef pair<Interval,pair<int,int>> pii;
    struct startCompare
    {
        bool operator()(const pii &a,const pii &b)
        {
            return a.first.start>b.first.start;
        }
    };
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        if(schedule.size()==0) return res;
        priority_queue<pii,vector<pii>,startCompare> minH; //to store 1 interval from each employee
        for(int i=0;i<schedule.size();i++) //insert first interval of each employee in minH
            minH.push({schedule[i][0],{i,0}});
        Interval prev=minH.top().first;
        while(!minH.empty())
        {
            auto cur=minH.top();
            minH.pop();
            //if prev is not overlapped with next interval, insert a free time
            if(prev.end<cur.first.start)
            {
                res.push_back({prev.end,cur.first.start});
                prev=cur.first;
            }                
            else //overlapping, update prev 
            {
                if(prev.end<cur.first.end) prev=cur.first;
            }
            vector<Interval> employeeSchedule=schedule[cur.second.first];
            if(employeeSchedule.size()>cur.second.second+1)
            {
                minH.push({employeeSchedule[cur.second.second+1],{cur.second.first,cur.second.second+1}});
            }
        }
        return res;
        
    }
};