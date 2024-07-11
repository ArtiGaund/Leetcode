class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> openParenthesesIndices;
        vector<int> pair(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openParenthesesIndices.push(i);
            }
            if(s[i]==')'){
                int j=openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        string res;
        for(int cur=0,dir=1;cur<n;cur+=dir){
            if(s[cur]=='(' or s[cur]==')'){
                cur=pair[cur];
                dir=-dir;
            }else res+=s[cur];
        }
        return res;
    }
};