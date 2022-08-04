class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
       int n=arr.size();
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(arr[cur]==0) return true;
            if(cur+arr[cur]<n and !vis.count(cur+arr[cur]))
            {
                q.push(cur+arr[cur]);
                vis.insert(cur+arr[cur]);
            }
            if(cur-arr[cur]>=0 and !vis.count(cur-arr[cur]))
            {
                q.push(cur-arr[cur]);
                vis.insert(cur-arr[cur]);
            }
        }
        return false;
    }
};