class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n=nums.size();
        vector<int> adj[n+1];
        vector<int> indegree(n+1,0);
        for(auto s:sequences)
        {
            for(int i=0;i<s.size()-1;i++)
            {
                adj[s[i]].push_back(s[i+1]);
                indegree[s[i+1]]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
            if(indegree[i]==0)
                q.push(i);
        int index=0;
        if(q.size()!=1) return false;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node!=nums[index++]) return false;
            for(auto it:adj[node])
            {
                if(--indegree[it]==0)
                    q.push(it);
            }
            if(q.size()>1)  return false;
        }
        return index==n;
    }
};