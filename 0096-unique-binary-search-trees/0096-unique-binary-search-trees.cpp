class Solution {
public:
    unordered_map<int,int> mp;
    int numTrees(int n) {
        if(mp.find(n)!=mp.end()) return mp[n];
        if(n<=1) return 1;
        int count=0;
        for(int i=1;i<=n;i++)
        {
            int left=numTrees(i-1);
            int right=numTrees(n-i);
            count+=(left*right);
        }
        mp[n]=count;
        return count;
    }
};