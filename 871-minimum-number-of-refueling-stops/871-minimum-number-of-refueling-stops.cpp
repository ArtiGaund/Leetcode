class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        priority_queue<int> maxH;
        int ans=0,prev=0;
        for(auto station:stations)
        {
            int loc=station[0];
            int cap=station[1];
            fuel-=(loc-prev);
            while(!maxH.empty() and fuel<0)
            {
                fuel+=maxH.top();
                maxH.pop();
                ans++;
            }
            if(fuel<0) return -1;
            maxH.push(cap);
            prev=loc;
        }
        fuel-=(target-prev);
        while(!maxH.empty() and fuel<0)
        {
            fuel+=maxH.top();
            maxH.pop();
            ans++;
        }
        if(fuel<0) return -1;
        return ans;
    }
};