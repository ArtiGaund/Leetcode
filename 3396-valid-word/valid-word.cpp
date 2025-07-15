class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool has_vowel=false,has_consonant=false;
        for(auto ch:word){
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'|| ch=='o'||ch=='u')
                    has_vowel=true;
                else has_consonant=true;
            }else if(!isdigit(ch)) return false;
        }
        return has_vowel && has_consonant;
    }
};