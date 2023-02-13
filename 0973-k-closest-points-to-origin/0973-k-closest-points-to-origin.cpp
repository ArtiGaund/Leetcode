class Solution {
public:
    typedef pair<double,vector<int>> pii;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii> maxHeap;
        for(int i=0;i<k;i++)
        {
            double dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            maxHeap.push({dist,points[i]});
        }
        for(int i=k;i<points.size();i++)
        {
            double dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            if(dist<maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({dist,points[i]});
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty())
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};