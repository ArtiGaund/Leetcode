class Solution {
public:
    int res=0;
    void maxRequest(vector<vector<int>> &req,vector<int> &indegree,int n,int index,int count)
    {
        if(index==req.size())
        {
            for(int i=0;i<n;i++)
                if(indegree[i]) return;
            res=max(res,count);
            return;
        }
        indegree[req[index][0]]--;
        indegree[req[index][1]]++;
        // Move on to the next request and also increment the count of requests.
        maxRequest(req, indegree, n, index + 1, count + 1);
        // Backtrack to the previous values to move back to the original state before the second recursion.
        indegree[req[index][0]]++;
        indegree[req[index][1]]--;
        
        maxRequest(req, indegree, n, index + 1, count);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n,0);
        maxRequest(requests,indegree,n,0,0);
        return res;
    }
};