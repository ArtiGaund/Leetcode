typedef pair<vector<int>,double> pii;
class Solution {
public:
    struct compare
    {
      bool operator()(pii p1,pii p2)
      {
          return p1.second<p2.second;
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii,vector<pii>,compare> pq;
        for(int i=0;i<k;i++)
        {
            double dis=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            pq.push({points[i],dis});
        }
        for(int i=k;i<points.size();i++)
        {
            double dis=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            if(dis<pq.top().second)
            {
                pq.pop();
                pq.push({points[i],dis});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};