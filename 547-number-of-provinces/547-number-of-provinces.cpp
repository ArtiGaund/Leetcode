class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        stack<int> st;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                st.push(i);
                count++;
                while(!st.empty())
                {
                    int cur=st.top();
                    st.pop();
                    vis[cur]=1;
                    for(int j=0;j<isConnected[cur].size();j++)
                    {
                        if(!vis[j] and isConnected[cur][j]==1)
                        {
                            st.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};