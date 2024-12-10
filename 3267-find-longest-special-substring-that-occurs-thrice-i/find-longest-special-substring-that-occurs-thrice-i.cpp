class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int> count;
        int subLen=0;
        for(int start=0;start<s.size();start++){
            char ch=s[start];
            subLen=0;
            for(int end=start;end<s.size();end++){
                if(ch==s[end]){
                    subLen++;
                    count[{ch,subLen}]++;
                }else break;
            }
        }
        int res=0;
        for(auto i:count){
            int len=i.first.second;
            if(i.second>=3 and len>res) res=len;
        }
        if(res==0) return -1;
        return res;
    }
};