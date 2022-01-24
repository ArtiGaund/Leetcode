class Solution {
public:
    bool detectCapitalUse(string word) {
        int s=0,cap=0;
        for(char c:word)
        {
            if(isupper(c)) cap++;
            else s++;
        }
        if(s==word.size() or cap==word.size())
            return true;
        else if(word[0]>='A' and word[0]<='Z' and s==word.size()-1) return true;
        return false;
    }
};