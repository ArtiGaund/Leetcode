class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right=arr.size()-1;
        while(right>0 and arr[right]>=arr[right-1]){
            right--;
        }
        int res=right;
        int left=0;
        while(left<right and (left==0 or arr[left-1]<=arr[left])){
            while(right<arr.size() and arr[left]>arr[right]){
                right++;
            }
            res=min(res,right-left-1);
            left++;
        }
        return res;
    }
};