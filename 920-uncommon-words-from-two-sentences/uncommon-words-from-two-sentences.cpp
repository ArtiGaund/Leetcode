class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp;
        string temp="";
        for(char ch:s1){
            if(ch==' '){
                mp[temp]++;
                temp="";
            }else temp+=ch;
        }
        if(temp.size()>0){
            mp[temp]++;
            temp="";
        }
        for(char ch:s2){
             if(ch==' '){
                mp[temp]++;
                temp="";
            }else temp+=ch;
        }
        if(temp.size()>0){
            mp[temp]++;
            temp="";
        }
        vector<string> res;
        for(auto it:mp){
            if(it.second==1) res.push_back(it.first);
        }
        return res;
    }
};