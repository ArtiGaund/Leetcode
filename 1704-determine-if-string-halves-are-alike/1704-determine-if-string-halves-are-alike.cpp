class Solution {
public:
    bool isvowel(char s)
    {
        if(s=='a' or s=='e' or s=='i' or s=='o' or s=='u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int a=0,b=0;
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(isvowel(tolower(s[l])))
                a++;
            if(isvowel(tolower(s[r])))
                b++;
            l++;
            r--;
        }
        return a==b;
    }
};