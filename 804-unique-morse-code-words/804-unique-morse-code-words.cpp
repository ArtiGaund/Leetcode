class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for(auto word:words)
        {
            string cur="";
            for(auto ch:word)
                cur+=codes[ch-97];
            res.insert(cur);
        }
        return res.size();
    }
};