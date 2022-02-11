typedef pair<int,int> pii;
class Solution {
public:
    struct compare
    {
        bool operator()(pii p1,pii p2)
        {
            if(p1.second==p2.second) return p1.first<p2.first;
            return p1.second<p2.second;
        }
    };
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pii,vector<pii>,compare> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],abs(nums[i]-x)});
            if(i>=k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};