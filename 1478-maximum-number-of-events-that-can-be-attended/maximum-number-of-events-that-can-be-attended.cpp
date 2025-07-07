class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=events.size();
        int maxDay=0;
        for(auto a:events){
            maxDay=max(maxDay,a[1]);
        }
        int res=0;
        for(int i=0,j=0;i<=maxDay;i++){
            while(j<n and events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() and pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};