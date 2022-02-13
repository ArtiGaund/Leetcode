class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(A.begin(),A.end());
        int res=0,i=0,n=A.size();
        for(int d=1;d<=100000;d++)
        {
            while(pq.size() and pq.top()<d) pq.pop();
            while(i<n and A[i][0]==d) pq.push(A[i++][1]);
            if(pq.size())
            {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};