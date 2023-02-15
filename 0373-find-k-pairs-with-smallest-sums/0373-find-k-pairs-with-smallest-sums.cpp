class Solution {
public:
    struct sumComp
    {
        bool operator()(const pair<int,int> &x,const pair<int,int> &y)
        {
            return x.first+x.second<y.first+y.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> minHeap;
        for(int i=0;i<nums1.size() and i<k;i++)
        {
            for(int j=0;j<nums2.size() and j<k;j++)
            {
                if(minHeap.size()<k)
                {
                    minHeap.push_back({nums1[i],nums2[j]});
                    push_heap(minHeap.begin(),minHeap.end(),sumComp());
                }
                else
                {
                    if(nums1[i]+nums2[j]>minHeap.front().first+minHeap.front().second)
                    break;
                    else
                    {
                        pop_heap(minHeap.begin(),minHeap.end(),sumComp());
                        minHeap.pop_back();
                        minHeap.push_back({nums1[i],nums2[j]});
                        push_heap(minHeap.begin(),minHeap.end(),sumComp());
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<minHeap.size();i++)
            res.push_back({minHeap[i].first,minHeap[i].second});
        return res;
    }
};