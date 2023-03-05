class Solution {
public:
    int minJumps(vector<int>& arr) {
         int n=arr.size();
        if(n<=1) return 0;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++) graph[arr[i]].push_back(i);
        queue<int> lq,rq;
        vector<int> left(n),right(n);
        lq.push(0);
        rq.push(n-1);
        left[0]=1;
        right[n-1]=1;
        while(!lq.empty() and !rq.empty())
        {
            int node=lq.front();
            lq.pop();
            if(node-1>=0 and !left[node-1])
            {
                left[node-1]=left[node]+1;
                lq.push(node-1);
                if(right[node-1]) return left[node-1]+right[node-1]-2;
            }
            if(node+1<n and !left[node+1])
            {
                left[node+1]=left[node]+1;
                lq.push(node+1);
                if(right[node+1]) return left[node+1]+right[node+1]-2;
            }
            for(auto i:graph[arr[node]])
            {
                if(!left[i])
                {
                    left[i]=left[node]+1;
                    lq.push(i);
                    if(right[i]) return left[i]+right[i]-2;
                }
            }
            node=rq.front();
            rq.pop();
            if(node-1>=0 and !right[node-1])
            {
                right[node-1]=right[node]+1;
                rq.push(node-1);
                if(left[node-1]) return left[node-1]+right[node-1]-2;
            }
            if(node+1<n and !right[node+1])
            {
                right[node+1]=right[node]+1;
                rq.push(node+1);
                if(left[node+1]) return left[node+1]+right[node+1]-2;
            }
            for(auto i:graph[arr[node]])
            {
                if(!right[i])
                {
                    right[i]=right[node]+1;
                    rq.push(i);
                    if(left[i]) return left[i]+right[i]-2;
                }
            }
        }
        return -1;
    }
};