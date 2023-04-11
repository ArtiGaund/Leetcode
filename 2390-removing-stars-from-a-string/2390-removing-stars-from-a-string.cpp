class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char ch:s)
        {
            if(ch=='*') st.pop();
            else st.push(ch);
        }
        string res="";
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};