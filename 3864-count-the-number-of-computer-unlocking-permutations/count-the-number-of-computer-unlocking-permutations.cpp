class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        if(*min_element(complexity.begin()+1,complexity.end())<=complexity[0]) return 0;
        int mod=1e9+7;
        int res=1;
        for(int i=2;i<n;i++)
            res=static_cast<long long>(res)*i%mod;
        return res;
    }
};