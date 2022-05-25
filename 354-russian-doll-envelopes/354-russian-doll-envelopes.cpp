class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        sort(env.begin(),env.end(),comp); //sort by height, if height are eq then descending order of width
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int ele=env[i][1];
            int index=lower_bound(res.begin(),res.end(),ele)-res.begin();
            if(index>=res.size()) res.push_back(ele);
            else res[index]=ele;
        }
        return res.size();
    }
};