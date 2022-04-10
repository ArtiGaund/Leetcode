class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string s:ops)
        {
            if(s=="+")
            {
                int t1=st.top();
                st.pop();
                int t2=t1+st.top();
                st.push(t1);
                st.push(t2);
            }
            else if(s=="C")
                st.pop();
            else if(s=="D")
                st.push(2*st.top());
            else st.push(stoi(s));
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};