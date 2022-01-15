class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
       set<int> vis;
        vis.insert(0);
        queue<int> q;
        q.push(0);
        for(int level=0;!q.empty();level++)
        {
            int size=q.size();
            while(size--)
            {
                int cur=q.front();
                q.pop();
                if(cur==n-1) return level;
                int i=cur;
                if(i-1>=0 and !vis.count(i-1))
                {
                    q.push(i-1);
                    vis.insert(i-1);
                }
                if(i+1<n and !vis.count(i+1))
                {
                    q.push(i+1);
                    vis.insert(i+1);
                }
                for(int j=0;j<mp[arr[cur]].size();j++)
                {
                    if(!vis.count(mp[arr[cur]][j]))
                    {
                        q.push(mp[arr[cur]][j]);
                        vis.insert(mp[arr[cur]][j]);
                    }
                }
                if(mp.count(arr[cur])) mp.erase(arr[cur]);
            }
        }
        return -1;
        
    }
};