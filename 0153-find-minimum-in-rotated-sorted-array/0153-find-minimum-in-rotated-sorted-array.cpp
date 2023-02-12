class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0,end=arr.size()-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(mid<end and arr[mid]>arr[mid+1]) return arr[mid+1];
            if(mid>start and arr[mid-1]>arr[mid]) return arr[mid];
            if(arr[start]<arr[mid]) start=mid+1;
            else end=mid-1;
        }
        return arr[0];
    }
};