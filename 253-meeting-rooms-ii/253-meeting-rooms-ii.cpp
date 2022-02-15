class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> minH;
        for(auto v:intervals)
        {
            if(!minH.empty() and minH.top()<=v[0]) minH.pop();
            minH.push(v[1]);
        }
        return minH.size();
    }
};