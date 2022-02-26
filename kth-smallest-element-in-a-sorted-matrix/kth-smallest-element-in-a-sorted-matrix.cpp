class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pii,vector<pii>,greater<pii>> minH;
        int m=matrix.size(),n=matrix[0].size();
        if(m==0) return 0;
        if(m==1) return matrix[0][k-1];
        for(int i=0;i<m;i++)
            minH.push({matrix[i][0],{i,0}});
        int res=-1;
        while(!minH.empty() and k--)
        {
            auto temp=minH.top();
            minH.pop();
            res=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            if(j+1==n) continue;
            minH.push({matrix[i][j+1],{i,j+1}});
        }
        return res;
    }
};