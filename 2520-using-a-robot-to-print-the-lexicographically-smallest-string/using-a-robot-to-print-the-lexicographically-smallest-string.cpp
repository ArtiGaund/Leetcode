class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int> cnt;
        for(char ch:s){
            cnt[ch]++;
        }
        stack<char> st;
        string res;
        char minChar='a';
        for(char ch:s){
            st.emplace(ch);
            cnt[ch]--;
            while(minChar!='z' and cnt[minChar]== 0){
                minChar++;
            }
            while(!st.empty() and st.top()<=minChar){
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};