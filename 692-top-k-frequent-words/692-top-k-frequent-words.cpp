typedef pair<string,int> pii;
class Solution {
public:
    struct compare
    {
      bool operator()(pii p1,pii p2)
      {
          if(p1.second==p2.second) return p1.first<p2.first;
          return p1.second>p2.second;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string s:words) mp[s]++;
        priority_queue<pii,vector<pii>,compare> pq;
        int count=0;
        for(auto it:mp)
        {
            pq.push({it.first,it.second});
            count++;
            if(count>k) pq.pop();
        }
        vector<string> res;
        while(!pq.empty())
        {
            
            res.insert(res.begin(),pq.top().first);
            pq.pop();
        }
        return res;
    }
};