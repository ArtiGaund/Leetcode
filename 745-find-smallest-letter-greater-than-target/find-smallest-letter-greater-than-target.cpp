class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(target<letters[0] or target>letters[n-1]) return letters[0];
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target<letters[mid]) end=mid-1;
            else start=mid+1;
        }
        return letters[start%n];
    }
};