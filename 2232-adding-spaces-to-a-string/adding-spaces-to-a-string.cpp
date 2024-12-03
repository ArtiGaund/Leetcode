class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        res.reserve(s.size()+spaces.size());
        int spaceIndex=0;
        for(int i=0;i<s.size();i++){
            if(spaceIndex<spaces.size() and i == spaces[spaceIndex]){
                res+=' ';
                spaceIndex++;
            }
            res+=s[i];
        }
        return res;
    }
};