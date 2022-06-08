class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return 2;
            i++;
            j--;
        }
        return 1;
    }
};