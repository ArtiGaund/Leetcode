class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    string sortVowels(string s) {
        string temp;
        for(char ch:s){
            if(isVowel(ch)) temp+=ch;
        }
        sort(temp.begin(),temp.end());
        int j=0;
        string res;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                res+=temp[j++];
            } else{
                res+=s[i];
            }
        }
        return res;
    }
};