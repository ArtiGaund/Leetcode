class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char ch:s) letters.insert(ch);
        int res=0;
        for(char ch:letters){
            int i=-1,j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==ch){
                    if(i==-1) i=k;
                    j=k;
                }
            }
            unordered_set<char> between;
            for(int k=i+1;k<j;k++) between.insert(s[k]);
            res+=between.size();
        }
        return res;
    }
};