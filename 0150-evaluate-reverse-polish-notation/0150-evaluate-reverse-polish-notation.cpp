class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto s:tokens)
        {
            if(s=="+" or s=="-" or s=="*" or s=="/")
            {
                long a=st.top();
                st.pop();
                long b=st.top();
                st.pop();
                if(s=="+") st.push(a+b);
                else if(s=="-") st.push(b-a);
                else if(s=="*") st.push(a*b);
                else st.push(b/a);
            }
            else
            {
                int n=stoi(s);
                st.push(n);
            }
        }
        return st.top();
    }
};