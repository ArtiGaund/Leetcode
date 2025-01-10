class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq2(26,0);
        vector<string> res;
        for(int i=0;i<words2.size();i++){
            string cur=words2[i];
            vector<int> temp(26,0);
            for(char ch:cur){
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }
        for(int i=0;i<words1.size();i++){
            vector<int> freq1(26,0);
            string cur=words1[i];
            bool flag=true;
            for(char ch:cur){
                freq1[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                if(freq2[i]>freq1[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) res.push_back(cur);
        }
        return res;
    }
};