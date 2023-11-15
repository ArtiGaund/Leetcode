class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int> counts(n+1,0);
        for(int a:arr) counts[min(a,n)]++;
        int res=1;
        for(int num=2;num<=n;num++)
            res=min(res+counts[num],num);
        return res;
    }
};