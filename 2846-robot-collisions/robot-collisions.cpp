class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> indices(n),res;
        stack<int> st;
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        sort(indices.begin(),indices.end(),[&](int lhs,int rhs){
            return positions[lhs]<positions[rhs];
        });
        for(int cur:indices){
            if(directions[cur]=='R'){
                st.push(cur);
            }else{
                while(!st.empty() && healths[cur]>0){
                    int top=st.top();
                    st.pop();
                    if(healths[top]>healths[cur]){
                        healths[top]-=1;
                        healths[cur]=0;
                        st.push(top);
                    }else if(healths[top]<healths[cur]){
                        healths[cur]-=1;
                        healths[top]=0;
                    }else{
                        healths[cur]=0;
                        healths[top]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0) res.push_back(healths[i]);
        }
        return res;
    }
};