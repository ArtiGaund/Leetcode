class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n=s.size();
        int cur=0;
        while(cur<n){
            res.push_back(s.substr(cur,k));
            cur+=k;
        }
        res.back()+=string(k-res.back().length(),fill);
        return res;
    }
};