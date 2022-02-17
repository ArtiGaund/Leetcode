class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(target<letters[0]) return letters[0];
        int low=0,high=n;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(target>=letters[mid]) low=mid+1;
            else high=mid;
        }
        return letters[low%n];
    }
};