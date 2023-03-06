class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128,0);
        for(char ch:s) count[ch]++;
        int res=0;
        for(int v:count)
        {
            res+=v/2*2;
            if(res%2==0 and v%2==1) res++;
        }
        return res;
    }
};