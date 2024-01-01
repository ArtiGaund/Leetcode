class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int contentChildren=0,cookieIndex=0;
        while(cookieIndex<s.size() and contentChildren<g.size()){
            if(s[cookieIndex]>=g[contentChildren]){
                contentChildren++;
            }
            cookieIndex++;
        }
        return contentChildren;
    }
};