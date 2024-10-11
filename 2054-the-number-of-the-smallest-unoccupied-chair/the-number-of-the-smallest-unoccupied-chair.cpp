class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> leavingQ;
        int targetArrival=times[targetFriend][0];
        sort(times.begin(),times.end());
        int nextChair=0;
        set<int> availChairs;
        for(auto time:times){
            int arrival=time[0];
            int leave=time[1];
            while(!leavingQ.empty() and leavingQ.top().first<=arrival){
                availChairs.insert(leavingQ.top().second);
                leavingQ.pop();
            }
            int cur;
            if(!availChairs.empty()){
                cur=*availChairs.begin();
                availChairs.erase(availChairs.begin());
            }else cur=nextChair++;
            leavingQ.push({leave,cur});
            if(arrival==targetArrival) return cur;
        }
        return 0;
    }
};