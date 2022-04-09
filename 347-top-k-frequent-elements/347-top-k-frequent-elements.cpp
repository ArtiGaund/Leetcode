class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int a:nums) mp[a]++;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        while(pq.size()>k) pq.pop();
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};