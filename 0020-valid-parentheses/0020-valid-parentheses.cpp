class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s)
        {
            if(ch=='(') st.push(')');
            else if(ch=='{') st.push('}');
            else if(ch=='[') st.push(']');
            else
            {
                if(st.empty() or st.top()!=ch) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};