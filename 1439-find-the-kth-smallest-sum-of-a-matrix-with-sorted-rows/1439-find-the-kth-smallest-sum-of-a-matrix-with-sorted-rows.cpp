class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        if(m==1) return mat[0][k-1];
        vector<int> ans=kSmallestPairs(mat[0],mat[1],k);
        for(int i=2;i<m;i++)
            ans=kSmallestPairs(ans,mat[i],k);
        return ans[k-1];
    }
    vector<int> kSmallestPairs(vector<int> &nums1,vector<int> &nums2,int k)
    {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<nums1.size();i++)
            pq.push({nums1[i]+nums2[0],{i,0}});
        vector<int> res;
        while(!pq.empty() and k--)
        {
            auto temp=pq.top();
            pq.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            int sum=temp.first;
            res.push_back(sum);
            if(j+1==nums2.size()) continue;
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return res;
    }
};