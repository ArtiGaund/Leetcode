class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int start=INT_MAX,end=INT_MIN;
        for(auto interval:intervals){
            start=min(start,interval[0]);
            end=max(end,interval[1]);
        }
        vector<int> pointToCount(end+2,0);
        for(auto interval:intervals){
            pointToCount[interval[0]]++;
            pointToCount[interval[1]+1]--;
        }
        int concurrentIntervals=0;
        int maxConcurrentIntervals=0;
        for(int i=start;i<=end;i++){
            concurrentIntervals+=pointToCount[i];
            maxConcurrentIntervals=max(maxConcurrentIntervals,concurrentIntervals);
        }
        return maxConcurrentIntervals;
    }
};