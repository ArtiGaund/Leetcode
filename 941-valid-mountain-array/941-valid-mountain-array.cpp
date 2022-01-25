class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i+1<n and arr[i]<arr[i+1]) i++; //walk up
        if(i==0 or i==n-1) //peak cn't be first or last
            return false;
        while(i+1<n and arr[i]>arr[i+1]) //walk down
            i++;
        return i==n-1;
    }
};