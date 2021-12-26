class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        int n=arr.size();
        vector<long long> pref(n,0),suf(n,0),ans(n,0);
        for(auto &it:mp)
        {
            auto vec=it.second;
            for(int i=1;i<vec.size();i++)
                pref[vec[i]]=pref[vec[i-1]]+i*(long)(vec[i]-vec[i-1]);
        }
        for(auto &it:mp)
        {
            auto vec=it.second;
            for(int i=vec.size()-2;i>=0;i--)
                suf[vec[i]]=suf[vec[i+1]]+long(vec.size()-1-i)*(vec[i+1]-vec[i]);
        }
        for(int i=0;i<n;i++) ans[i]=pref[i]+suf[i];
        return ans;
    }
};