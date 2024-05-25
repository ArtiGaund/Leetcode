class Solution {
public:
    int maxScore;
    vector<int> freq;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        freq=vector<int>(26,0);
        vector<int> subsetLetters(26,0);
        for(char ch:letters) freq[ch-'a']++;
        check(n-1,words,score,subsetLetters,0);
        return maxScore;
    }
    bool isValidWord(vector<int> &subsetLetters){
        for(int c=0;c<26;c++){
            if(freq[c]<subsetLetters[c]) return false;
        }
        return true;
    }
    void check(int w,vector<string> &words,vector<int> &score, vector<int> &subsetLetters,int totalScore){
        if(w==-1){
            maxScore = max(maxScore,totalScore);
            return;
        }
        check(w-1,words,score,subsetLetters,totalScore);
        int L=words[w].length();
        for(int i=0;i<L;i++){
            int ch=words[w][i]-'a';
            subsetLetters[ch]++;
            totalScore+=score[ch];
        }
        if(isValidWord(subsetLetters)){
            check(w-1,words,score,subsetLetters,totalScore);
        }
        for(int i=0;i<L;i++){
            int ch=words[w][i]-'a';
            subsetLetters[ch]--;
            totalScore-=score[ch];
        }
    }
};