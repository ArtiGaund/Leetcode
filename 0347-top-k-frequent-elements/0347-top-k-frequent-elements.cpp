class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto it:mp)
        {
            minHeap.push({it.second,it.first});
            if(minHeap.size()>k) minHeap.pop();
        }
        vector<int> res;
        while(!minHeap.empty())
        {
            res.push_back({minHeap.top().second});
            minHeap.pop();
        }
        return res;
    }
};