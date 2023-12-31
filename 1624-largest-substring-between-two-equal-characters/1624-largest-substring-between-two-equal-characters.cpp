class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> firstIndex;
        int res=-1;
        for(int i=0;i<s.size();i++){
            if(firstIndex.find(s[i])!=firstIndex.end()){
                res=max(res,i-firstIndex[s[i]]-1);
            }else{
                firstIndex[s[i]]=i;
            }
        }
        return res;
    }
};