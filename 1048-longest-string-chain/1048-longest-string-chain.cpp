class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> mp;
        int n=words.size();
        for(int i=0;i<n;i++)
            mp[words[i]]=i;
        // graph
        vector<int> graph[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                auto temp=words[i].substr(0,j)+words[i].substr(j+1);
                if(mp.count(temp))
                    graph[mp[temp]].push_back(i);
            }
        }
        //topo sort
        vector<int> indegree(n,0);
        for(auto it:graph)
        {
            for(int x:it)
                indegree[x]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push(i);
        int res=0;
        while(!q.empty())
        {
            int size=q.size();
            res++;
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                for(auto it:graph[temp])
                {
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
        }
        return res;
    }
};