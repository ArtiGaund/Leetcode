class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                cnt[s[i]-'a'].push(i);
            }else{
                for(int j=0;j<26;j++){
                    if(!cnt[j].empty()){
                        s[cnt[j].top()]='*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};