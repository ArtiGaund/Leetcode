class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(')');
            else if(s[i]=='{') st.push('}');
            else if(s[i]=='[') st.push(']');
            else
            {
                if(st.empty() or st.top()!=s[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};