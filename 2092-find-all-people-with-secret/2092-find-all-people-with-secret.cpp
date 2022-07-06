class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<meetings.size();i++)
        {
            adj[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); //time, person
        pq.push({0,firstPerson});
        vector<bool> knows(n,0);
        while(!pq.empty())
        {
            auto [curTime,curPerson]=pq.top();
            pq.pop();
            if(knows[curPerson]) continue;
            knows[curPerson]=1;
            for(auto it:adj[curPerson])
            {
                if(!knows[it.first] and curTime<=it.second)
                    pq.push({it.second,it.first});
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(knows[i]) res.push_back(i);
        return res;
    }
};