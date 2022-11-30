class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a:arr) mp[a]++;
        unordered_set<int> st;
        for(auto it:mp) st.insert(it.second);
        return mp.size()==st.size();
    }
};