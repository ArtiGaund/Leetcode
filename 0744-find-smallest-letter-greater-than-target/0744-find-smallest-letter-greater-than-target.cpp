class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char key) {
        int n=letters.size();
        if(key<letters[0] or key>letters[n-1]) return letters[0];
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(key<letters[mid]) end=mid-1;
            else start=mid+1;
        }
        return letters[start%n];
    }
};