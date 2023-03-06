class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int total_missing=0;
        if(arr[0]!=1)
        {
            if(arr.size()>1) total_missing=arr[0]-1;
            else
            {
                if(arr[0]<=k) return k+1;
                return k;
            }
        }
        if(total_missing>=k) return k;
        for(int i=1;i<arr.size();i++)
        {
            int cur_missing=(arr[i]-arr[i-1]-1);
            if(total_missing+cur_missing>=k)
                return arr[i-1]+(k-total_missing);
            total_missing+=cur_missing;
        }
        return arr[arr.size()-1]+(k-total_missing);
    }
};