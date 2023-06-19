class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0;
        int high=cur;
        for(auto a:gain)
        {
            cur+=a;
            high=max(high,cur);
        }
        return high;
    }
};