class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
//         convert sentences to lists of words
        stringstream ss1(s1),ss2(s2);
        string word;
        vector<string> s1Words,s2Words;
        while(ss1>>word) s1Words.push_back(word);
        while(ss2>>word) s2Words.push_back(word);
        int start=0,end1=s1Words.size()-1,end2=s2Words.size()-1;
        if(s1Words.size()>s2Words.size()) return areSentencesSimilar(s2,s1);
        while(start<s1Words.size() and s1Words[start]==s2Words[start]) ++start;
        while(end1>=0 and s1Words[end1]==s2Words[end2]){
            --end1;
            --end2;
        }
        return end1<start;
    }
};