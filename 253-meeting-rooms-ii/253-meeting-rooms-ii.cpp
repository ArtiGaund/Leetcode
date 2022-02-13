class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),compare);
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0;i<intervals.size();i++)
        {
            if(!minH.empty() and minH.top()<=intervals[i][0]) minH.pop();
            minH.push(intervals[i][1]);
        }
        return minH.size();
    }
};