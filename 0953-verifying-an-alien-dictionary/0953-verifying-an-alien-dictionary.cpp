class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMp(26,0);
        for(int i=0;i<order.size();i++) orderMp[order[i]-'a']=i;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(j>=words[i+1].size()) return false;
                string word1=words[i];
                string word2=words[i+1];
                if(word1[j]!=word2[j])
                {
                    int curWordChar=word1[j]-'a';
                    int nextWordChar=word2[j]-'a';
                    if(orderMp[curWordChar]>orderMp[nextWordChar]) return false;
                    else break;
                }
            }
        }
        return true;
    }
};