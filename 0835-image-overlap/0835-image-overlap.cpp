class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA,LB;
        int n=A.size();
        for(int i=0;i<n*n;i++)
        {
            if(A[i/n][i%n]==1)
                LA.push_back(i/n*100+i%n);
            if(B[i/n][i%n]==1)
                LB.push_back(i/n*100+i%n);
        }
        unordered_map<int,int> count;
        for(int i:LA)
            for(int j:LB)
                count[i-j]++;
        int res=0;
        for(auto it:count)
            res=max(res,it.second);
        return res;
    }
};