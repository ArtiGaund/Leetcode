class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int res=0,maxEle=0;
        for(int i=0;i<n;i++){
            maxEle=max(maxEle,arr[i]);
            if(maxEle==i) res++;
        }
        return res;
    }
};