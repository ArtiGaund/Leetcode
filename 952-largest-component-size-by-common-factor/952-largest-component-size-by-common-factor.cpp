class Solution {
public:
    vector<int> parent,rank;
    int find(int x)
    {
        if(parent[x]==-1) return x;
        return parent[x]=find(parent[x]);
    }
    void unionset(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            if(rank[x]>=rank[y])
            {
                parent[y]=x;
                rank[x]+=rank[y];
            }
            else
            {
                parent[x]=y;
                rank[y]+=rank[x];
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        parent=vector<int>(n,-1);
        rank=vector<int>(n,1);
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            for(int j=2;j*j<=x;j++)
            {
                if(x%j==0)
                {
                    if(mp.count(j))
                        unionset(mp[j],i);
                    else
                        mp[j]=i;
                    if(mp.count(x/j))
                        unionset(mp[x/j],i);
                    else
                        mp[x/j]=i;
                }
            }
            if(mp.count(x))
                unionset(mp[x],i);
            else
                mp[x]=i;
            res=max(res,rank[find(i)]);
        }
        return res;
    }
};