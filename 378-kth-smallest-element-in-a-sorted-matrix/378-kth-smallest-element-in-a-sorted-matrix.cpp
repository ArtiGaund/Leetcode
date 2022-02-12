class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<m;i++)
            pq.push({matrix[i][0],{i,0}});
        int n=matrix[0].size();
        int val=-1;
        while(!pq.empty() and k--)
        {
            auto temp=pq.top();
            pq.pop();
            val=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            if(j+1==n) continue;
            pq.push({matrix[i][j+1],{i,j+1}});
        }
        return val;
    }
};