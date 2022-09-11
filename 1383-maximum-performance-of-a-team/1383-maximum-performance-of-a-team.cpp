class Solution {
public:
    const int mod=(int)1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& e, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({e[i],speed[i]});
        sort(v.rbegin(),v.rend());
        long total=0,res=0;
        for(int i=0;i<n;i++)
        {
            int cur_e=v[i].first;
            int cur_s=v[i].second;
            if(pq.size()==k)
            {
                total-=pq.top();
                pq.pop();
            }
            pq.push(cur_s);
            total+=cur_s;
            res=max(res,total*cur_e);
        }
        return res%mod;
    }
};