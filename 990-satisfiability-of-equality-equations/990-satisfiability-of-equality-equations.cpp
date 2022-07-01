class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> graph[26];
        for(string &s:equations)
        {
            if(s[1]=='=')
            {
                int x=s[0]-'a';
                int y=s[3]-'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        vector<int> color(26,0);
        int t=0;
        for(int start=0;start<26;start++)
        {
            if(color[start]==0)
            {
                t++;
                stack<int> st;
                st.push(start);
                while(!st.empty())
                {
                    int node=st.top();
                    st.pop();
                    for(int nei:graph[node])
                    {
                        if(color[nei]==0)
                        {
                            color[nei]=t;
                            st.push(nei);
                        }
                    }
                }
            }
        }
        for(string &s:equations)
        {
            if(s[1]=='!')
            {
                int x=s[0]-'a';
                int y=s[3]-'a';
                if(x==y or (color[x]!=0 and color[x]==color[y])) return false;
            }
        }
        return true;
    }
};