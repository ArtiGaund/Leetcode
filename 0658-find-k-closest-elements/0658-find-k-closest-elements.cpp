typedef pair<int,int> pii;
class Solution {
public:
    struct comp
    {
        bool operator()(pii x,pii y)
        {
            if(x.second==y.second) return x.first<y.first;
            return x.second<y.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      priority_queue<pii,vector<pii>,comp> minHeap;
        for(int i=0;i<arr.size();i++)
        {
            minHeap.push({arr[i],abs(arr[i]-x)});
            if(i>=k) minHeap.pop();
        }
        vector<int> res;
        while(!minHeap.empty())
        {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};