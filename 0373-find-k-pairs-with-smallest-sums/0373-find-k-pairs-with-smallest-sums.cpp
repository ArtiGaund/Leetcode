class Solution {
public:
    struct sumComp
    {
        bool operator()(const pair<int,int> &x,const pair<int,int> &y)
        {
            return y.first+y.second>x.first+x.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<pair<int,int>> maxHeap;
        for(int i=0;i<nums1.size() and i<k;i++)
        {
            for(int j=0;j<nums2.size() and j<k;j++)
            {
                if(maxHeap.size()<k)
                {
                    maxHeap.push_back({nums1[i],nums2[j]});
                    push_heap(maxHeap.begin(),maxHeap.end(),sumComp());
                }
                else
                {
                    if(nums1[i]+nums2[j]>maxHeap.front().first+maxHeap.front().second) break;
                    else 
                    {
                        pop_heap(maxHeap.begin(),maxHeap.end(),sumComp());
                        maxHeap.pop_back();
                        maxHeap.push_back({nums1[i],nums2[j]});
                        push_heap(maxHeap.begin(),maxHeap.end(),sumComp());
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<maxHeap.size();i++)
            res.push_back({maxHeap[i].first,maxHeap[i].second});
        return res;
    }
};