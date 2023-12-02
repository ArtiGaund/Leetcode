class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> counts;
        for(char ch:chars) counts[ch]++;
        int res=0;
        for(string word:words){
            unordered_map<char,int> wordCount;
            for(char ch:word) wordCount[ch]++;
            bool good=true;
            for(auto &[ch,freq]:wordCount){
                if(counts[ch]<freq){
                    good=false;
                    break;
                }
            }
            if(good) res+=word.size();
        }
        return res;
    }
};