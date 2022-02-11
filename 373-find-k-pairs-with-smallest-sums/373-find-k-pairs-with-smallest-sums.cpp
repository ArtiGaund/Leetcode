class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<nums1.size();i++) //pairing all elements of nums1 with 0th element ofnums2
            pq.push({nums1[i]+nums2[0],{i,0}});
        vector<vector<int>> res;
        while(!pq.empty() and k--) //finding pair with remaining elements of nums2
        {
            auto temp=pq.top();
            pq.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            res.push_back({nums1[i],nums2[j]});
            if(j+1==nums2.size()) continue; //reach end of nums2
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return res;
    }
};