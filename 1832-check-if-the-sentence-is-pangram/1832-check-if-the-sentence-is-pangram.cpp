class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(char &ch:sentence) st.insert(ch);
        return st.size()==26;
    }
};