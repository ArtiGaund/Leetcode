typedef pair<int,int> pii;
class Solution {
public:
    // struct compare
    // {
    //     bool operator()(pii p1,pii p2)
    //     {
    //     return p1.second>p2.second;
    //     }
    // };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
      for(int a:nums) mp[a]++;
      priority_queue<pii,vector<pii>,greater<pii>> pq;
      int count=0;
      for(auto it:mp)
      {
        pq.push({it.second,it.first});
        count++;
        if(count>k) pq.pop();
      }
      vector<int> res;
      while(!pq.empty())
      {
        res.push_back(pq.top().second);
        pq.pop();
      }
      return res;
    }
};