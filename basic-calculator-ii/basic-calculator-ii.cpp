class Solution {
public:
    int calculate(string s) {
       int n=s.size();
        long long int res=0;
        stack<int> st;
        long long int curnum=0;
        char lastop='+';
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c>='0'&& c<='9')
                curnum=curnum*10+c-'0';
            if(c == '+' or c == '-' or c == '*' or c == '/' or i == n - 1)
            {
                if(lastop=='+')
                    st.push(curnum);
                else if(lastop=='-')
                    st.push(-1*curnum);
                else if(lastop=='*')
                {
                    int attop=st.top();
                    st.pop();
                    curnum*=attop;
                    st.push(curnum);
                }
                else if(lastop=='/')
                {
                    int attop=st.top();
                    st.pop();
                    curnum=attop/curnum;
                    st.push(curnum);
                }
                curnum=0;
                lastop=c;
            }
        }
        while(!st.empty())
        {
            res=res+st.top();
            st.pop();
        }
        return res;
          
    }
};