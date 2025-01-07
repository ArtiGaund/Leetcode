class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        for(int cur=0;cur<words.size();cur++){
            vector<int> lps=computeLPS(words[cur]);
            for(int other=0;other<words.size();other++){
                if(cur==other) continue;
                if(isSubstringOf(words[cur],words[other],lps)){
                    matchingWords.push_back(words[cur]);
                    break;
                }
            }
        }
        return matchingWords;
    }
    vector<int> computeLPS(string &str){
        vector<int> lps(str.size(),0);
        int cur=1;
        int len=0;
        while(cur<str.size()){
            if(str[cur]==str[len]){
                len++;
                lps[cur]=len;
                cur++;
            }else{
                if(len>0){
                    len=lps[len-1];
                }else{
                    cur++;
                }
            }
        }
        return lps;
    }
    bool isSubstringOf(string &sub,string &main,vector<int> &lps){
        int mainIndex=0,subIndex=0;
        while(mainIndex<main.size()){
            if(main[mainIndex]==sub[subIndex]){
                subIndex++;
                mainIndex++;
                if(subIndex==sub.size()) return true;
            }else{
                if(subIndex>0) subIndex=lps[subIndex-1];
                else mainIndex++;
            }
        }
        return false;
    }
};