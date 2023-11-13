class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    string sortVowels(string s) {
       unordered_map<char,int> count;
        for(char ch:s){
            if(isVowel(ch)){
                count[ch]++;
            }
        }
        string sortedVowel="AEIOUaeiou";
        string res;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(!isVowel(s[i])) res+=s[i];
            else{
                while(count[sortedVowel[j]]==0) j++;
                res+=sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        return res;
    }
};